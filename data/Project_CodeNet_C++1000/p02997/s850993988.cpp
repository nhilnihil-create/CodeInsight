#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll n,k;
    cin>>n>>k;
    n--;
    int x=n/2,y=n/2;
    if(n%2)
        x++;
    int can=x*y;
    can+=(x*(x-1))/2;
    can+=(y*(y-1))/2;
    n++;
    if(can<k)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        int mid=(n+1)/2;
        vector<int>g[200];
        for(int i=1; i<mid; i++)
            g[i].push_back(mid);
        for(int i=mid+1; i<=n; i++)
            g[i].push_back(mid);
        for(int i=1; i<mid; i++)
        {
            if(can==k)
                break;
            for(int j=mid+1; j<=n; j++)
            {
                if(can==k)
                    break;
                g[i].push_back(j);
                can--;
            }
        }
        for(int i=1; i<mid; i++)
        {
            if(can==k)
                break;
            for(int j=i+1; j<mid; j++)
            {
                if(can==k)
                    break;
                g[i].push_back(j);
                can--;
            }
        }
        for(int i=mid+1; i<=n; i++)
        {
            if(can==k)
                break;
            for(int j=i+1; j<=n; j++)
            {
                if(can==k)
                    break;
                g[i].push_back(j);
                can--;
            }
        }
        int sz=0;
        for(int i=1; i<=n; i++)
        {
            sz+=g[i].size();
        }
        cout<<sz<<endl;
        for(int i=1; i<=n; i++)
            for(auto it:g[i])
                cout<<i<<" "<<it<<endl;

    }


    return 0;
}
