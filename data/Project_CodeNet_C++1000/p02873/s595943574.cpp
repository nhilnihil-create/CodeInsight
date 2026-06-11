#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

string S;

int main() {
    cin >> S;

    vector<ll> a(S.size() + 1);

    // < をみる
    rep(i, S.size()) {
        if (S[i] == '<') {
            a[i + 1] = max(a[i + 1], a[i] + 1);
        }
    }

    // > をみる
    for (int i = S.size() - 1; i >= 0; i--) {
        if (S[i] == '>') {
            // cout << "i: " << i << endl;
            // cout << i - 1 << " " << i << endl;
            a[i] = max(a[i], a[i + 1] + 1);
        }
    }
    
    // rep(i, a.size()) {
    //     cout << a[i] << endl;
    // }

    cout << accumulate(a.begin(), a.end(), 0LL) << endl;
}