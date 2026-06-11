#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    if(n % 2) return cout << 0, 0;
    ll ans = 0;
    for(ll i = 5; ;){
        ans += n / (2 * i);
        if(i > n / 5) break;
        i *= 5;
    }
    cout << ans;

    return 0;
}
