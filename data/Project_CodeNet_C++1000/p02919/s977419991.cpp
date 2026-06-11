
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << endl;
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REVFOR(i, m, n) for (int i = (n - 1); i >= (m); --i)
#define REP(i, n) FOR(i, 0, n)
#define REVREP(i, n) REVFOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;

    vector<int> P(N);
    REP(i, N) cin >> P[i];

    vector<int> I(N);
    REP(i, N) I[P[i] - 1] = i;

    ll ans = 0;

    reverse(ALL(I));
    set<int> s;
    s.insert(I[0]);
    s.insert(-1);
    s.insert(-2);
    s.insert(N);
    s.insert(N+1);
    FOR(i, 1, N) {
        s.insert(I[i]);

        auto it = s.find(I[i]);

        auto c1 = it;
        int p1 = *(--c1), p2 = *(--c1);

        auto c2 = it;
        int n1 = *(++c2), n2 = *(++c2);

        ll cnt = 0;

        if (p1 > -1) cnt += (p1 - p2) * (n1 - *it); // self + left
        if (n1 < N) cnt += (*it - p1) * (n2 - n1); // self + right

        ans += cnt * (N - i);
    }

    print(ans);

}
