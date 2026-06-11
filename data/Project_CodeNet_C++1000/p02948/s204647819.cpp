#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> A(n), B(n);
    rep(i, n) cin >> A[i] >> B[i];
    
    typedef pair<ll, ll> P;
    vector<P> p;
    rep(i, n) p.push_back(P{A[i], B[i]});
    sort(all(p));

    int cur = 0;
    priority_queue<P> que;
    ll res = 0;
    for (int i = 1; i <= m; i++) {
        while (cur < n && i - p[cur].first >= 0) {
            que.push(P{ p[cur].second, p[cur].first });
            cur++;
        }

        while (!que.empty()) {
            P q = que.top();
            que.pop();
            if (i - q.second >= 0) {
                res += q.first;
                break;
            }
        }
    }

    put(res);
}
signed main(){ Main();return 0;}