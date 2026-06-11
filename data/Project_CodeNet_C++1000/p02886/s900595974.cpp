#include <bits/stdc++.h>

using namespace std;

int n;
unsigned long long int res = 0;
vector<int> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    s.resize(n);
    for (int& i : s) cin >> i;
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) res += s[i] * s[j];
    cout << res << '\n';

    return 0;
}