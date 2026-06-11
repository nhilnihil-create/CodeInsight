#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

bool pal(string s, int a, int b) {
    a--;
    b--;
    int i = a;
    int j = b;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    if (pal(s, 1, n) && pal(s, 1, (n - 1) / 2) && pal(s, (n + 3) / 2, n)) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }

    fflush(stdout);
    return 0;
}
