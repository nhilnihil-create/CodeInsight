#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
#define mod 1000000007

int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> vec(n);
    rep(i,n) cin >> vec[i];
    ll ans=0,ans2=0;
    for(ll i=0;i<n;i++){
        ll total=0;
        for(ll j=0;j<n;j++){
            if(j==i){
                ans+=total;
                continue;
            }
            if(vec[j]>vec[i]) total++;
        }
        ans2+=total;
    }
    ll now=0;
    if((k-1)%2==0) now=(k%mod)*(k/2)%mod;
    else now=(k*(k/2-1)+k/2)%mod;
    ll ans3=0;
    ans3+=ans*k%mod;
    ans3+=now*ans2%mod;
    ans3=ans3%mod;
    cout << ans3 << endl;

    return 0;
}






