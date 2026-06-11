#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    int N;
    cin >> N;
    pli p[N];
    rep(i, N){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p, p+N, greater<pli>());
    multiset<ll> s;
    ll ans = 0;
    s.insert(-1), s.insert(-1), s.insert(N), s.insert(N);
    rep(i, N){
        int j = p[i].second;
        s.insert(j);
        multiset<ll>::iterator itel = s.find(j), iter = s.find(j);
        itel--, iter++;
        ll l1 = *itel, r1 = *iter;
        itel--, iter++;
        ll l2 = *itel, r2 = *iter;
        ll num = (j-l1)*(r2-r1) + (r1-j)*(l1-l2);
        ans += p[i].first*num;
    }
    cout << ans << endl;
}