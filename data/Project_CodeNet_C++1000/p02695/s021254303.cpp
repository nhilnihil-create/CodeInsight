#include <bits/stdc++.h>
using namespace std;

// TYPEDEF
// ----------------------------------------
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> Pair;
typedef vector<ll> vll;
typedef vector<vector<ll>> Graph;
typedef vector<string> vs;
typedef vector<pair<ll, ll>> Pll;

// REPEAT
// ----------------------------------------
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REPA(i,a) for(ll i=0;i<(ll)(a.size());i++);
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define COUT(a) cout << (a) << endl;
#define ENDL(a) cout << endl;
#define COUTA(i,a) for(ll i=0;i<(ll)(a.size());i++) {cout << (a)[i] << " ";} cout << endl;

// UTIL
// ----------------------------------------
#define pb push_back
#define paired make_pair
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define RSORT(a) sort((a).rbegin(), (a).rend())

// DEBUG
// ----------------------------------------
#ifdef _DEBUG
#define debug(x) cout << "[debug] " << #x << ": " << x << endl
#else
#define debug(x)
#endif

template <typename T>
void debugV(const vector<T> v) {
#ifdef _DEBUG
  rep(i, v.size()) {
    cout << i << ":" << v[i] << " ";
  }
  cout << endl;
#else
  (void)v;
#endif
}

// BIT FLAG
// ----------------------------------------
const unsigned int BIT_FLAG_0 = (1 << 0); // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4); // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5); // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6); // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7); // 0000 0000 1000 0000
const unsigned int BIT_FLAG_8 = (1 << 8); // 0000 0001 0000 0000
const unsigned int BIT_FLAG_9 = (1 << 9); // 0000 0010 0000 0000
const unsigned int BIT_FLAG_10 = (1 << 10); // 0000 0100 0000 0000
const unsigned int BIT_FLAG_11 = (1 << 11); // 0000 1000 0000 0000

// CONST
// ----------------------------------------
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr double PI=3.14159265358979323846; // or M_PI


ll calc_value(vll v, vll a, vll b, vll c, vll d) {
    ll total = 0;
    REP(i, a.size()) {
        if (v[b[i] - 1] - v[a[i] - 1] == c[i]) {
            total = total + d[i];
        }
    }
    return total;
}


void make_v(vll& v, ll n, ll m, vll a, vll b, vll c, vll d, ll& saidai) {

    if (v.size() == n) {
        saidai = max(saidai, calc_value(v, a, b, c, d));
    }
    else {
        ll start = (v.size() == 0) ? 1: v.back();
        FOR(i, start, m) {
            v.pb(i);
            make_v(v, n, m, a, b, c, d, saidai);
            v.pop_back();
        }
    }
}

void Main() {
    ll n, m, q;
    cin >> n >> m >> q;

    vll v;
    vll a(q), b(q), c(q), d(q);
    REP(i, q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    ll saidai = 0;
    make_v(v, n, m, a, b, c, d, saidai);
    COUT(saidai);

}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
}

/*

N M Q
3 4 3
1 3 3 100
1 2 2 10
2 3 2 10



*/