#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define pp pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
#define F first 
#define S second 
#define lc "\n"
ll power(ll x,ll y,ll p){ll res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;} 
ll MAX=1e18 , MIN=-1e18 , MOD=1000000007;
void YJ()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
int main() 
{
    YJ(); fastio
    int n; cin>>n;
    if(n>=400&&n<600) cout<<8;
    if(n>=600&&n<800) cout<<7;
    if(n>=800&&n<1000) cout<<6;
    if(n>=1000&&n<1200) cout<<5;
    if(n>=1200&&n<1400) cout<<4;
    if(n>=1400&&n<1600) cout<<3;
    if(n>=1600&&n<1800) cout<<2;
    if(n>=1800&&n<2000) cout<<1;
    return 0;
}