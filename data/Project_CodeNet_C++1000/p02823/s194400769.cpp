#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, A, B;
    cin >> N >> A >> B;
    A--;
    B--;
    if ((B - A) % 2 == 0) {
        cout << (B - A) / 2 << endl;
    } else {
        cout << min(A + 1 + (B - A - 1) / 2, N - B + (B - A - 1) / 2) << endl;
    }
}