#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define repk(i,m,n) for(ll i=m;i<n;i++)
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define F first
#define S second
typedef long long ll;
typedef long double ld;
using namespace std;
const int MOD1=1e9+7;
const int MOD2=998244353;
const int INF=2*1e9;
ll n;
void dfs(string s,ll k)
{
    if(s.size()==n) cout<<s<<"\n";
    else
    {
        char c='a';
        rep(i,k+1)
        {
            char t=c+i;
            string sp=s;
            sp.insert(sp.end(),1,t);
            if(i==k) dfs(sp,k+1);
            else dfs(sp,k);
        }
    }
}
int main()
{
    cin>>n;
    dfs("",0);
}
