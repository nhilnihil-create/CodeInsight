#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;
 
const int mod = 1e9 + 7;
vector<long long int> fac;
long long int mypow(long long int a, long long int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long int res = mypow(a, b / 2);
    res = res * res % mod;
    if (b % 2 == 1) res = res * a % mod;
    return res;
}
 
 
long long int myc(long long int a, long long int b) {
    return fac[a] * mypow(fac[b], mod - 2) % mod * mypow(fac[a - b], mod - 2) % mod;
}
 
int main() {
	int n, k;
    cin >> n >> k;
    fac.push_back(1);
    for (int i = 1; i <= k; i++) {
        fac.push_back(fac.back() * i % mod);
    }
    vector<unordered_set<int>> v(n + 1, unordered_set<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].insert(b);
        v[b].insert(a);
    }
    vector<pair<int, int>> v1, v2;
    long long int res = k;
    v1.push_back(make_pair(1, 1));
    while (v1.size() > 0) {
        v2.clear();
        for (auto p : v1) {
            int index = p.first, root = p.second;
            if (v[index].size() == 0) continue;
            if (v[index].size() > k - 1 - (1 - root)) {
                cout << 0 << endl;
                return 0;
            }
            res *= myc(k - 1 - (1 - root), v[index].size());
            res %= mod;
            res *= fac[v[index].size()];
            res %= mod;
            for (auto next : v[index]) {
                v[next].erase(index);
                v2.push_back(make_pair(next, 0));
            }
        }
        v1 = v2;
    }
    cout << res << endl;
}