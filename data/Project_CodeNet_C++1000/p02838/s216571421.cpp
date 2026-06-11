#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define fe 2*idx
#define fd fe+1
#define mid (l+r)/2
const int MAXN = 3e5+7;
const ll MOD = 1e9+7, UM=1;
ll a[MAXN], poten[62], um[62], zer[62];
inline ll soma_mod(ll x, ll y){return (x+y)%MOD;}
int main(){
    fastio;
    int n; cin>>n;
    poten[0] = 1;
    for(int i=1; i<60; i++)poten[i] = (2LL*poten[i-1])%MOD;

    for(int i=1; i<=n; i++){
        cin>>a[i];
        for(ll j=0; j<60; j++){
            if( ((UM<<j)&a[i]) )um[j]++;
            else zer[j]++;
        }
    }
    ll ans = 0;
    for(ll j=0; j<60; j++){
        ans = soma_mod(ans, poten[j]*( (um[j]*zer[j])%MOD ));
    }
    cout<<ans<<endl;
}