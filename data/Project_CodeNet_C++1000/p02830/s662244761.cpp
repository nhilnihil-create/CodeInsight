#include <bits/stdc++.h>

using namespace std;

#define long long long
#define INF 2e18
#define MOD (long) (1e9 + 7)
#define umap unordered_map

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long t = 1;
    //cin >> t;

    while (t--) {
        long n;
        string s, t;
        cin >> n >> s >> t;

        for (long i = 0; i < n; i++) {
            putchar(s[i]);
            putchar(t[i]);
        }
        puts("");
    }
}
