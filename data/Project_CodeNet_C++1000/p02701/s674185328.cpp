#include <bits/stdc++.h>

using namespace std;

#define long long long
#define INF 2e18
#define MOD (long) (998244353)
#define umap unordered_map

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long t = 1;
    //cin >> t;

    while (t--) {
        long n;
        cin >> n;

        set<string> s;
        while (n--) {
            string x;
            cin >> x;
            s.insert(x);
        }
        long ans = s.size();
        printf("%lld\n", ans);
    }
}
