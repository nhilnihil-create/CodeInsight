#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

string solve() {
    ll n; cin >> n;
    string s = "";
    while (n > 0) {
        ll rem = (n % 26);
        if (rem == 0) rem = 26;
        s = char(rem - 1 + 'a') + s;
        n -= rem;
        n /= 26;
    };

    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve() << endl;
}
