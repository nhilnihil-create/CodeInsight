#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 100000;

int main() {
    ll ans = 0;
    string S;
    cin >> S;
    string before = "";
    string t = "";
    for (int i = 0; i < S.size(); i++) {
        if (i == 0) {
            ans++;
            before += S[i];
            continue;
        }
        t += S[i];
        if (t == before) {
            t += S[i];
        } else {
            ans++;
            before = t;
            t = "";
        }
    }
    if (t == before) {
        ans--;
    }
    cout << ans << endl;
}
