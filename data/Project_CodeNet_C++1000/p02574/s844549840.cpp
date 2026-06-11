#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

bool is_prime[2000000];

int a[2000000];
vector<int> v[2000000];

int main() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < 2000000; i++) {
        if (!is_prime[i]) continue;
        v[i].push_back(i);
        for (int j = 2 * i; j < 2000000; j += i) {
            is_prime[j] = false;
            v[j].push_back(i);
        }
    }
    int n;
    cin >> n;
    int g = 0;
    unordered_map<int, int> mp;
    rep(i, n) {
        scanf("%d", &a[i]);
        g = __gcd(g, a[i]);
        for (int u : v[a[i]]) {
            mp[u]++;
        }
    }
    bool ok = true;
    for (auto p : mp) {
        if (p.second != 1) ok = false;
    }
    if (ok)
        puts("pairwise coprime");
    else if (g == 1)
        puts("setwise coprime");
    else
        puts("not coprime");
}