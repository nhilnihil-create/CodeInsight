#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n, m;
    cin >> n >> m;
    int *p = new int[m];
    string *s = new string[m];
    bool *ac = new bool[n + 5];
    int *wa = new int[n + 5];
    for (int i = 0; i < m; i++) {
        cin >> p[i] >> s[i];
    }
    for (int i = 0; i < n + 5; i++) {
        ac[i] = false;
        wa[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        if (ac[p[i]] == false) {
            if (s[i] == "AC") {
                ac[p[i]] = true;
            } else {
                wa[p[i]]++;
            }
        }
    }
    int accept = 0, wrong = 0;
    for (int i = 1; i <= n; i++) {
        if (ac[i]) {
            accept++;
            wrong += wa[i];
        }
    }
    cout << accept << " " << wrong << endl;
    return 0;
}