#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SUM(a) accumulate(all(a), 0LL)
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define FOR(i, m, n) for(int (i)=(m); (i)<(n); i++)
#define FORR(i, m, n) for(int (i)=(n)-1; (i)>=(m); i--)
#define debug(x) cerr << #x << " = " << x << endl
//#define int long long

typedef long long ll;
//ll const MOD = 998244353;
ll const MOD = 1e9+7;
int const inf = 1e9;
ll const INF = 1e18;

inline void ios_(){cin.tie(0); ios::sync_with_stdio(false);}
template<typename T> int size(const T& a){return (int)a.size();}
template<typename T> T Div(T a, T b){return (a + b - 1) / b;}
template<typename T> bool chmin(T& a, const T& b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, const T& b){if(a < b){a = b; return true;} return false;}

ll BinarySearch(ll ng, ll ok, function<bool(ll)> judge){
    while(abs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;
        if(judge(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

signed main(){
    ll n, m, v, p;
    cin >> n >> m >> v >> p;

    vector<int> score(n);
    for(auto&& i : score) cin >> i;

    sort(rall(score));

    auto fn = [&](ll x){
        ll vote = m * v;
        ll s = x + m;

        REP(i, n){
            if(i < p - 1){
                vote -= m;
                continue;
            }
            if(score[i] > s){
                return false;
            }
            ll d = s - score[i];
            vote -= min(d, m);
        }

        return vote <= 0;
    };

    ll bound = BinarySearch(-1, score[0], fn);

    int ans = 0;
    REP(i, n){
        if(score[i] >= bound) ans++;
        else break;
    }

    cout << ans << endl;
    return 0;
}
