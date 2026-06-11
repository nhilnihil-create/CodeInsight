#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

const int maxn = 1000100;

int main() {
    int x;
    string s;
    cin >> x >> s;

    // array went thru the step by 1
    // sure made out of {0,1,2} from then on
    vector<int> a;
    rep(i, s.size() - 1) {
        a.push_back(abs(s[i] - s[i + 1]));
    }
    int n = a.size();

    // # of times n! can be devided by 2
    vector<ll> cnt(maxn, 0);
    for (int i = 1; i < maxn; i++) {
        int num = i;
        int toAdd = 0;
        while (num % 2 == 0) {
            toAdd++;
            num /= 2;
        }
        cnt[i] = cnt[i - 1] + toAdd;
    }

    ll parity = 0;
    rep(i, n) {
        ll val = cnt[n - 1] - cnt[i] - cnt[n - i - 1];
        if (val > 0) continue;
        parity += a[i];
    }

    // if the parity is odd, the answer is 1
    if (parity & 1) {
        cout << 1 << endl;
        return 0;
    }

    // if there is 1 in a, the answer is 0
    rep(i, n) {
        if (a[i] == 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    parity = 0;
    rep(i, n) {
        ll val = cnt[n - 1] - cnt[i] - cnt[n - i - 1];
        if (val > 0) continue;
        parity += a[i] / 2;
    }
    cout << (parity & 1 ? 2 : 0) << endl;
}