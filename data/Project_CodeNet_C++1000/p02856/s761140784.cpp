#include <bits/stdc++.h>

#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);

typedef long long ll;
const int maxn = 100010;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int m;
    cin >> m;
    ll res = 0, sum = 0;
    for(int i = 1; i <= m; i ++){
        ll d, c;
        cin >> d >> c;
        res += c;
        sum += d * c;
    }
    cout << res - 1 + (sum - 1) / 9 << endl;
    return 0;
}