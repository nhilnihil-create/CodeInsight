#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2000 + 10, mod = 1e9 + 7;
int a[N],n,k;
ll f(ll x){
    return x * (x + 1) / 2 % mod;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) if(a[i]<a[j]){
            if(i>j) ans += f(k);
            else ans += f(k-1);
        }
    }
    ans %= mod;
    cout<<ans<<endl;
}
