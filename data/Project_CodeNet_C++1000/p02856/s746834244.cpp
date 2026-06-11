#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    int M;
    cin >> M;
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < M; ++i) {
        ll c, d;
        cin >> d >> c;
        sum += c * d;
        ans += c;
    }
    ans--;
    while (sum / 10){
        ans += sum / 10;
        sum = sum % 10 + sum / 10;
    }
    cout << ans << "\n";
    return 0;
}