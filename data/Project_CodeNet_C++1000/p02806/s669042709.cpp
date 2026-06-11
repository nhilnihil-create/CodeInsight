#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 1001001001001001001;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

int main(){
    ll N;
    cin >> N;
    vector<pair<string,ll>> A(N);
    rep(i,N) cin >> A[i].first >> A[i].second;
    string X;
    cin >> X;
    ll ans = 0;
    bool flag = 0;
    rep(i,N){
        if(flag) ans += A[i].second;
        if(X == A[i].first) flag = 1;
    }
    cout << ans << endl;
}
