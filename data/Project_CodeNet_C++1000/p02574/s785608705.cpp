#include <bits/stdc++.h>
#define ll long long
#define pb(x) push_back((x))
#define line() cerr << "DEBUG @" << __LINE__ << endl;
#define debug(x) \
    cerr << "DEBUG @" << __LINE__ << " -> " << #x << " = " << x << endl;
using namespace std;

const int MAX = 1e6;
int v[MAX], divisors[MAX + 1], m[MAX + 1];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    for (int i = 2; i <= MAX; i++) {
        if (!divisors[i]) {
            for (int j = i; j <= MAX; j += i) {
                divisors[j] = i;
            }
        }
    }
    bool pair_wise_coprime = true;
    bool gcd_is_one = true;

    for (int i = 0; i < n; i++) {
        int x = v[i];
        int cur = x;
        set<int> q;
        while (cur != 1) {
            q.insert(divisors[cur]);
            cur /= divisors[cur];
        }
        for (int div : q) {
            m[div]++;
            if (m[div] > 1) pair_wise_coprime = false;
            if (m[div] == n) gcd_is_one = false;
        }
    }
    if (pair_wise_coprime) {
        puts("pairwise coprime");
        return 0;
    }
    if (gcd_is_one) {
        puts("setwise coprime");
        return 0;
    }
    puts("not coprime");
}
