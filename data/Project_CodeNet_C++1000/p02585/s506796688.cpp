#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5000 + 15;

ll p[MAXN], c[MAXN];
vector <ll> v;
int main() {

    ll n, k;
    scanf("%lld %lld", &n, &k);

    for(int i = 1; i <= n; i++) scanf("%lld", &p[i]);
    for(int i = 1; i <= n; i++) scanf("%lld", &c[i]);

    ll res = -1e18;
    for(int i = 1; i <= n; i++) {
        v.clear();
        ll sum = c[i];
        v.push_back(sum);

        int j = p[i];
        while(j != i) {
            sum += c[j];
            v.push_back(sum);
            j = p[j];
        }

        int len = (int)v.size();
        for(j = 0; j < len; j++) {
            ll rest = k - 1 - j;
            if(rest < 0) break;
            res = max(res, v[j] + (rest / len) * max(sum, 0ll));
        }
    }

    printf("%lld\n", res);

    return 0;
}
