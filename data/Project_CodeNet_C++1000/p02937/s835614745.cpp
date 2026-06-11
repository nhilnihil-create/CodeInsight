#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    string s,t;
    cin >> s >> t;
    ll N = s.size();
    ll M = t.size();
    string ss = s + s;
    vector<ll> v[26];
    rep(i,N*2){
        v[ss[i]-'a'].push_back(i);
    }
    ll ans = 0;
    ll cur = 0;
    rep(i,M){
        ll c = t[i] - 'a';
        auto itr = lower_bound(v[c].begin(), v[c].end(), cur);
        if(itr == v[c].end()){
            cout << -1 << endl;
            return 0;
        }
        ll q = *itr - cur +1;
        ans += q;
        cur = *itr;
        cur++;
        if(cur > N){
            cur -= N;
        }
    }
    cout << ans << endl;
}