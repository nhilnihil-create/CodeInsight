#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)

const int N = 1e6 + 10;
int n, a[N];

int solve() {
    int ans = 0;
    for (int k = 0; k <= n; k++) {
        ans += ((k&(n-1)) == k) * a[k] % 2;
        ans %= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    bool one = 0;
    cin >> n; 
    string s; cin >> s;

    forn(i,n) {
        cin >> a[i];
        a[i] = s[i]-'0';
        one |= a[i] == 2;
    }

    int factor = one ? 1 : 2;
    forn(i,n) a[i] /= factor;

    cout << factor*solve() << endl;

    return 0;
}
