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
        long k;
        cin >> k;

        if (k <= 9) printf("%lld\n", k);
        else {
            vector<long> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            set<long> s, aux;
            s.insert(v.begin(), v.end());
            while (v.size() < k) {
                for (auto &y : s) {
                    long x = y * 10;
                    long z = (x % 100) / 10;
                    if (z > 0) v.push_back(x + z - 1);
                    v.push_back(x + z);
                    if (z < 9) v.push_back(x + z + 1);
                    if (z > 0) aux.insert(x + z - 1);
                    aux.insert(x + z);
                    if (z < 9) aux.insert(x + z + 1);
                }
                s = aux;
                aux.clear();
            }
            sort(v.begin(), v.end());
            printf("%lld\n", v[k-1]);
        }
    }
}
