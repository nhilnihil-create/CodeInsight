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

const int N = 1e6+228;

int par[N], cnt[N];

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

    for (int i = 2; i < N; i++) {
        if (par[i] != 0) continue;
        for (int j = i << 1; j < N; j += i)
            par[j] = i;
    }

    int n, g = 0;
    cin >> n;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        g = __gcd(g, t);
        int last = -1;
        while (par[t] != 0) {
            int x = par[t];
            t = t / par[t];
            if (last != x) {
                last = x;
                cnt[x]++;
            }
        }
        if (last != t && t != 1)
            cnt[t]++;
    }
    if (g != 1) {
        cout << "not coprime";
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (cnt[i] > 1) {
            cout << "setwise coprime";
            return 0;
        }
    }
    cout << "pairwise coprime";

    return 0;
}

// 272472LF
