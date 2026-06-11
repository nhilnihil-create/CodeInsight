#include <bits/stdc++.h>

using namespace std;

#define long long long
#define INF ((long) 2e18)
#define MOD ((long) (1e9 + 7))
#define umap unordered_map

int main()
{
    ios::sync_with_stdio(true); cin.tie(0); cout.tie(0);

    long t = 1;
    //cin >> t;

    while (t--) {
        long n;
        string s;
        cin >> n >> s;

        long count = 0;
        for (long i = 0; i < n - 2; i++) {
            count += s.substr(i, 3) == "ABC";
        }
        printf("%lld\n", count);
    }
}
