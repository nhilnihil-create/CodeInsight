#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ll N;
    cin >> N;
    // 10^N - 9^N - 9^N + 8^N
    ll a, b, c;
    ll m = 1000000000+7;
    a = b = c = 1;
    for (int i = 0; i < N; i++) {
        a *= 10, b *= 9, c *= 8;
        a %= m, b %= m, c %= m;
    }
    cout << ((a+c-b-b) % m + m + m) % m << endl;
}