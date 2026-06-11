#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define pll pair<ll,ll>
#define plii pair<ll,pii>
#define vi vector<int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mx 100001
#define eps 0.00000000001
#define mod 1000000007
#define pi acos(-1)
#define inf 100000000
#define loop(i,b,n) for(int i=b;i<n;++i)
#define rev_loop(i,b,n) for(int i=b;i>=n;--i)
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
    fio;
    int n;
    cin>>n;
    int a1;
    vi v1,v2;
    int sum = 0;
    int ans = (n*(n-1))/2;
    loop(i,0,n)
    {
        cin>>a1;
        v1.pb(a1);
    }
    SORT(v1);
    loop(i,0,n)
    {
        if(v1[i]!=0)
        {
            int k = v1[i];
            loop(j,i+1,n)
            {
             v2.pb(k*v1[j]);
            }
        }
    }
    int b = v2.size();
    int h = min(b,ans);
    loop(i,0,h)
    sum += v2[i];
    cout<<sum<<endl;
    return 0;
}

