#include <bits/stdc++.h>


using namespace std;


using ll = long long;


int main(void) {
    ll A, B, N;
    cin >> A >> B >> N;
    ll x;
    if (B - 1 > N) {
        x = N;
    } else {
        x = B - 1;
    }
    ll ans = ((A * x) / B) - A * (x / B);
    cout << ans << endl;
}
