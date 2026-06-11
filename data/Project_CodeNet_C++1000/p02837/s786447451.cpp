#include <bits/stdc++.h>
using namespace std;
using ll= long long;
using ld= long double;
using pll= pair<ll, ll>;
using vi= vector<int>;
using vl= vector<ll>;
using vd= vector<ld>;
using vs= vector<string>;
using vb= vector<bool>;
using vpll= vector<pll>;
using vvi= vector<vi>;
using vvl= vector<vl>;
using vvd= vector<vd>;
using vvs= vector<vs>;
using vvb= vector<vb>;
using vvpll= vector<vpll>;
constexpr ll mod= 1e9 + 7;
#define ALL(x) (x).begin(), (x).end()
#define _overload(_1, _2, _3, name, ...) name
#define REPBASE(i, a, b) for(ll(i)= (a); (i) < (b); (i)++)
#define RREPBASE(i, a, b) for(ll(i)= (a); (i) >= (b); (i)--)
#define REPB(i, n) REPBASE(i, 0, n)
#define REPS(i, n) REPBASE(i, 1, n + 1)
#define RREP(i, n) RREPBASE(i, n - 1, 0)
#define RREPS(i, n) RREPBASE(i, n, 1)
#define REP(...) _overload(__VA_ARGS__,REPBASE,REPB)(__VA_ARGS__)
#define EACH(x,c) for(auto& x : c)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())
#define YES(n) ((n) ? "YES" : "NO")
#define Yes(n) ((n) ? "Yes" : "No")
#define yes(n) ((n) ? "yes" : "no")
#define SZ(x) ((ll)(x).size())
#define BIT(n) (1LL<<(n))
template <class T>
bool chmax(T &a, const T &b) {
    if(a < b) {
        a= b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if(b < a) {
        a= b;
        return 1;
    }
    return 0;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    ll N;
    cin >> N;
    vl A(N);
    vvpll X(N,vpll(0));
    REP(i,N){
        cin >> A[i];
        X[i].assign(A[i],mp(0,0));
        REP(l,A[i]){
            cin >> X[i][l].fi >> X[i][l].se;
            X[i][l].fi--;
        }
    }
    ll count = 0;
    REP(i,BIT(N)){
        bool ok = 1;
        REP(l,N){
            if((i & BIT(l)) != 0){
                REP(k,A[l]){
                    if(X[l][k].se == 0){
                        if((i & BIT(X[l][k].fi)) != 0){
                            ok = 0;
                            break;
                        }
                    }else{
                        if((i & BIT(X[l][k].fi)) == 0){
                            ok = 0;
                            break;
                        }
                    }
                }
            }
            if(!ok)break;
        }
        if(ok)chmax(count,(ll)__builtin_popcountll(i));
    }
    cout << count << "\n";
}