#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int inf = 1000000000;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    rep(i,n+1){
        a[i] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            a[j]++;
        }
    }
    ll ans = 0;
    rep(i,n+1) ans += i*a[i];
    cout << ans << endl;

}