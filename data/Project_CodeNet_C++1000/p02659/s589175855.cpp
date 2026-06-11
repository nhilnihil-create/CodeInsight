#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll solve() {
    ll a, b1; cin >> a >> b1; // b: integer part of a decimal
    char c; cin >> c; // capture decimal point "."
    ll b2; cin >> b2; // capture decimal part
    ll d = b1 * 100 + b2;
    return a * d / 100;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << solve() << endl;
}
