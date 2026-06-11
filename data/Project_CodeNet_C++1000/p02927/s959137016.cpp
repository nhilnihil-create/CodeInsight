#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define mp make_pair
#define F first
#define S second
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define INF 0x3f3f3f3f
typedef long long ll;
ll n;

int main()
{
    // ios_base::sync_with_stdio(0),cin.tie(0);
    ll m,d;
    while(cin>>m>>d)
    {
        ll sum=0;
        rep1(i,m)
        {
            for(int j=10;j<=d;j++)
            {
                if(j<100)
                {
                    if(j/10>=2&&j%10>=2)
                    if(j/10*(j%10)==i) sum++;
                }
            }
        }
        cout<<sum<<'\n';
    }
}

