#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    ll ans = 1e12;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            ans = min(ans, i + (n / i));
        }
    }
    cout << ans - 2;

    return 0;
}
