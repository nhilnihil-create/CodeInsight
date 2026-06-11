#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    string t; cin >> t;

    for (int i = 0; i < t.size(); ++i) {
        if (i - 1 >= 0 && t[i] == '?' && t[i - 1] == 'P') {
            t[i] = 'D';
            continue;
        }

        if (i == t.size() - 1 && t[i] == '?') {
            t[i] = 'D';
            continue;
        }

        if (t[i] == '?' && t[i + 1] == 'D') {
            t[i] = 'P';
            continue;
        }

        if (t[i] == '?' && t[i + 1] == 'P') {
            t[i] = 'D';
            continue;
        }

        if (t[i] == '?' && t[i + 1] == '?') {
            if (i - 1 >= 0 && t[i - 1] == 'P') {
                t[i] = 'D';
                t[i + 1] = 'P';
                continue;
            } else {
                t[i] = 'P';
                t[i + 1] = 'D';
                continue;
            }
        }

        if (t[i] == '?') {
            t[i] = 'D';
            continue;
        }
    }

    cout << t << endl;
}