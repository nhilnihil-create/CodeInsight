#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pll = pair<ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define Rep(i, m, n) for(ll i = m; i < n; i++)
#define all(vec) vec.begin(), vec.end()
#define tmax(x, y, z) max((x), max((y), (z)))
#define tmin(x, y, z) min((x), min((y), (z)))
#define MINUS(a) memset(a, 0xff, sizeof(a))
#define ZERO(a) memset(a, 0, sizeof(a))
const ll INF = 1LL << 60;
const ll MM = 1000000000; const ll MOD = MM + 7; const ll MMM=9223372036854775807;//2^63 -1
#define ADD(a,b) a = (a + ll(b)) % MOD
#define MUL(a,b) a = (a * ll(b)) % MOD
ll GCD(ll x, ll y){ if(y == 0) return x; else return GCD(y, x % y);}
ll LCM(ll x, ll y){ return x / GCD(x, y) * y;}
template<class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return true;} return false;}
template<typename A, size_t N, typename T> void FILL(A (&array)[N], const T &val){ fill( (T*)array, (T*)(array+N), val );}
using Graph = vector<vector<ll>>;
ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
ll ddx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//cout << fixed << setprecision(10);

vector<ll> v;

ll counter(ll t){
    ll cnt = 0;
    rep(i, v.size()){
        if(v[i] == t) cnt++;
    }
    return cnt;
}


int main(){
    ll n; cin >> n;
    set<ll> s;
    v.resize(n);
    rep(i, n){
        cin >> v[i];
        s.insert(v[i]);
    }
    if(s.size() == 3){
        ll x = 0;
        vector<ll> nums;
        for(auto p: s){
            x ^= p;
            nums.push_back(p);
        }
        if(x == 0 && counter(nums[0]) == counter(nums[1]) && counter(nums[1]) == counter(nums[2])) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if(s.size() == 2){
        sort(all(v));
        if(v[0] == 0 && counter(0) * 3 == n && counter(v[n-1]) == n * 2 / 3) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if(s.size() == 1){
        if(v[0] == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
