#include <bits/stdc++.h>
/*#ifndef LOCAL_RUN
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    #pragma GCC optimize("fast-math")
    #pragma GCC target("avx2,tune=native")
#endif*/
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    #ifdef LOCAL_RUN
        freopen("input.txt", "r", stdin);
    //#else
        //freopen("cowcode.in", "r", stdin);
        //freopen("cowcode.out", "w", stdout);
    #endif
	ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size(),
        ans = m;
    for (int i = 0; i <= n - m; i++) {
        int x = 0;
        for (int j = 0; j < m; j++)
            x += int(s[i+j] != t[j]);
        ans = min(ans, x);
    }
    cout << ans;

    return 0;
}

// 272472LF
