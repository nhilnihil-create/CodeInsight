
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
#define REP(i, n) FOR(i, 0, n)
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
    cout << fixed << setprecision(20);
    typedef long double ld;

    ld a, b, x;
    cin >> a >> b >> x;


    ld ng = 90, ok = 0;
    ld eps = 1e-12;
    REP(i, 50) {
       ld mid = (ok + ng) / 2;

       ld t = tan(mid * M_PI / 180);
       if (x / a / a - a * t / 2 > eps) {
           if (x / a / a + a * t / 2 > b + eps) ng = mid;
           else ok = mid;
       } else {
           if (sqrt(2 * x * t / a) > b + eps) ng = mid;
           else ok = mid;
       }

       debug(ng, ok);
    }

    print(ok);
    
}
