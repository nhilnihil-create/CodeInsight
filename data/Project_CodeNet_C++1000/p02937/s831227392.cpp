#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    string S,T;
    cin >> S >> T;
    string SS = S + S;
    ll N = S.size();
    ll M = T.size();
    vector<vector<ll>> v(26);
    rep(i,SS.size()){
        v[SS[i]-'a'].push_back(i+1);
    }
    ll ans = 0;
    ll cur = 0;
    rep(i,M){
        ll c = T[i] - 'a';
        auto itr = upper_bound(v[c].begin(), v[c].end(), cur);
        if(itr == v[c].end()){
            cout << -1 << endl;
            return 0;
        }
        ll pos = *itr;
        ans += pos - cur;
        cur += pos - cur;
        if(cur > N){
            cur -= N;
        }
    }
    cout << ans << endl;
}