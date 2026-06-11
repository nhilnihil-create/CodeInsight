#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
#define umi2357 	ios::sync_with_stdio(0);cin.tie(0);
const ll maxn=2e5+7;
ll n,p,ans=0,cnt[maxn],res,dp[maxn],a[maxn];
string s;
int main(void){
    cin>>n>>p;
    cin>>s;
    res=1;
    dp[n]=0;
    if(p==2||p==5){
        rep(0,i,n){
            if((s[i]-'0')%p==0)ans+=i+1;
        }
    }else{
        rep(0,i,n){
            ll x=n-1-i;
            a[x]=s[x]-'0';
            dp[x]=(dp[x+1]+a[x]*res)%p;
            res=(res*10)%p;
            ++cnt[dp[x]];
        }
        rep(0,i,p){
            ll x=cnt[i];
            ans+=x*(x-1)/2;
        }
        ans+=cnt[0];
    }
    cout<<ans;
}