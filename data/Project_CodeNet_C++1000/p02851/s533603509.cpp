#include <bits/stdc++.h>

using namespace std;

const int M = 2e5 + 5;

int n, k, ps[M];
long long int sm = 0, res = 0;
map<int, int> c; // Maintain count
vector<long long int> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    s.resize(n);
    for (auto& i : s) {
        cin >> i;
        i = (i + k - 1) % k; // Precalc Value
    } c[0]++;
    for (int i = n - 1; i >= 0; i--) {
        sm = (sm + s[i]) % k; ps[i] = sm;
        if (i + k <= n) c[ps[i + k]]--;
        res += c[sm]; c[sm]++;
    } cout << res << '\n';

    return 0;
}