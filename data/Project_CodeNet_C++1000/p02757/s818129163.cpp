#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n, p, c = 0;
        string s;
        cin >> n >> p >> s;
        ll sol = 0;
        if (p == 2 || p == 5) {
                for (int i = 0; i < n; i++) {
                        int x = s[i] - '0';
                        if (x % p == 0)
                                sol += i + 1;
                }
                cout << sol << "\n";
                return 0;
        }
        vector<int> put(n);
        put[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
                put[i] = 10 * put[i + 1] % p;
        vector<int> f(p, 0);
        f[0]++;
        for (int i = 0; i < n; i++) {
                int x = s[i] - '0';
                c = (c + put[i] * x) % p;
                sol += f[c]++;
        }
        cout << sol << "\n";
        return 0;
}
