#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;

bool dcl(P a, P b){
    return atan2(a.first, a.second) < atan2(b.first, b.second);
}

int main(){
    ll N; cin >> N;
    vector<P> C(N);
    rep(i, 0, N){
        ll a, b; cin >> a >> b;
        C[i] = mp(a, b);
    }
    sort(C.begin(),C.end(),dcl);
    vector<P> D(0);
    rep(i, 0, N){
        D.emplace_back(C[i]);
    }
    rep(i, 0, N){
        D.emplace_back(C[i]);
    }
    long double ma = 0;
    ll v = 0;
    rep(i, 0, N){
        rep(j, i+1, i+N+1){
            ll m = 0, n = 0;
            rep(k, i, j){
                m += D[k].first; n += D[k].second;  
            }
            ma = max(ma, sqrtl(m*m + n*n));
            v++;
        }
    }
    //prtl(v);
    cout << setprecision(15) << ma;
}
