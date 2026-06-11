#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define verify(x) if(x >= MOD) x -= MOD;

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n,k; cin>>n>>k;
    vi arr(n);
    FOR(i, 0, n) {
        cin>>arr[i]; arr[i]--;
    }
    ll res = 0; map<int, ll> cnt; cnt[0] = 1;
    ll prefs[n + 1]; prefs[0] = 0;
    FOR(i, 0, n) {
        prefs[i + 1] = (prefs[i] + arr[i])%k;
        if(i >= k - 1) {
            cnt[prefs[i - k + 1]]--;
        }
        if(cnt.count(prefs[i + 1])) {
            res += 1LL * cnt[prefs[i + 1]];
            cnt[prefs[i + 1]]++;
        } else {
            cnt.insert({prefs[i + 1], 1});
        }
    }
    cout << res;
    return 0;
}