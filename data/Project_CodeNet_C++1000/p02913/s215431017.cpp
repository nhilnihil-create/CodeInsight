#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
const int INF = 1e18;
 
class RollingHash{
    const int mod = 1e9+7;
    const int base = 1007;
    vector<int> hash, power;
public:
    RollingHash(const string &s){
        int n = SZ(s);
        hash.assign(n+1, 0);
        power.assign(n+1, 1);
        REP(i,n){
            hash[i+1] = (hash[i] * base + s[i]) % mod;
            power[i+1] = (power[i] * base) % mod;
        }
    }
    inline int get(int l, int r) const {
        int res = hash[r] - hash[l] * power[r-l] % mod;
        if(res < 0) res += mod;
        return res;
    }
    inline int s_hash(){return get(0,SZ(hash));}

    inline int getLCP (int a, int b) const {
        int len = min(SZ(hash)-a, SZ(hash)-b);
        int ok = 0, ng = len;
        while(abs(ok-ng) > 1){
            int mid = (ok+ng) / 2;
            if(get(a, a+mid) != get(b, b+mid)) ng = mid;
            else ok = mid;
        }
        return ok;
    }
};
 
signed main(){
    int n; string s; cin >> n >> s;
    RollingHash rh(s);
    int ans = 0;
    auto judge = [&](int d){
        map<int,int> mp;
        REP(i,n-d+1){
            int v = rh.get(i, i+d);
            if(mp.count(v)){
                if(i - mp[v] >= d) return true;
            }
            else mp[v] = i;
        }
        return false;
    };
    int ok = 0, ng = n/2 + 1;
    while(abs(ok-ng) > 1){
        int mid = (ok+ng) / 2;
        if(judge(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << '\n';
}