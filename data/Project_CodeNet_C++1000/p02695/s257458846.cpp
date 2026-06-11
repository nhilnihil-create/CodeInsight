#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")

typedef long long ll;
typedef long double ld;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define fast() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
#define eb emplace_back
#define pb push_back
#define deb(a) cerr << #a << " = " << a << '\n';

ll n, m, q, a[50], b[50], c[50], d[50], ans = 0;
vector<ll> t;

void rec(ll idx) {
    if(idx == n) {
        ll sum = 0;
        for(int i = 0; i < q; i++)
            if(t[b[i]-1] - t[a[i]-1] == c[i])
                sum += d[i];
        ans = max(ans, sum);
        return;
    }
    for(int i = t[(idx ? idx - 1 : 0)]; i <= m; i++) {
        t[idx] = i;
        rec(idx + 1);
    }
}

int main()
{
    fast();
    cin >> n >> m >> q;
    t = vector<ll> (n, 1);
    for(int i = 0; i < q; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    rec(0);
    cout << ans;
    return 0;
}
