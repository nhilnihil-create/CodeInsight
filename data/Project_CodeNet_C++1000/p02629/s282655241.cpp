#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

string solve() {
    ll n; cin >> n;
    string s = "";
    while (n > 0) {
        n -= 1;
        s += n % 26 + 'a';
        n /= 26;
    };
    reverse(s.begin(), s.end());

    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve() << endl;
}
