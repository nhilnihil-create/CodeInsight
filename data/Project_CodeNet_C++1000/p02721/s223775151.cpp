# include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;

int n, k, c;
int pf[N], sf[N];
string s;

int main() {
    cin >> n >> k >> c;
    cin >> s;
    s = ' ' + s;

    for (int i = n; i >= 1; i--) {
        if (s[i] == 'o') {
            sf[i] = 1;
            if (i + c + 1 <= n)
                sf[i] += sf[i + c + 1];
        }
        sf[i] = max(sf[i], sf[i + 1]);
    }

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'o') {
            pf[i] = 1;
            if (i - c - 1 >= 1)
                pf[i] += pf[i - c - 1];
        }
        pf[i] = max(pf[i - 1], pf[i]);
    }

    for (int i = 1; i <= n; i++) {
        int ret = sf[i + 1] + pf[i - 1];
        if (ret < k && s[i] == 'o') {
            cout << i << endl;
        }
    }
}
