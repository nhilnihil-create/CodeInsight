#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
const ll MAXN = 205;
pair<ll,ll> a[MAXN];
 
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return atan2(a.second,a.first) < atan2(b.second,b.first);
}
 
void solve(){
    ll n; cin>>n;
 
   for(ll i=1;i<=n;++i) cin>>a[i].first>>a[i].second;
 
    sort(a+1,a+n+1,cmp);
 
    for(ll i=n+1;i<=2*n;++i) a[i] = a[i-n];
 
    ll ans = 0;
 
    for(ll i=1;i<=n;++i){
        ll x = 0,y = 0;
        for(ll j=i;j<=i+n-1;++j){
            x = x + a[j].first,y = y + a[j].second;
            ans = max(ans,x*x + y*y);
        }
    }
 
    ld ans1 = sqrtl(ans+.0);
 
    cout<<fixed<<setprecision(17)<<ans1<<endl;
} 
 
int main(){
 
   FastIO;    

        solve();
}