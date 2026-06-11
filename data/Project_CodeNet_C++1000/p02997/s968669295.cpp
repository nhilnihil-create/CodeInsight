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
    ll N, K;
    cin >> N >> K;
    ll MaxK = (N-1)*(N-2)/2;
    if(K > MaxK){
        cout << -1 << endl;
        return 0;
    }
    vector<Pll> v;
    rep(i,N-1){
        v.push_back(Pll(1,i+2));
    }
    ll cnt = MaxK - K;
    REP(i,2,N+1){
        REP(j,i+1,N+1){
            if(cnt == 0) goto gt;
            v.push_back(Pll(i,j));
            cnt--;
        }
    }
    gt:
    cout << v.size() << endl;
    for(auto& p:v){
        cout << p.fi << " " << p.se << endl;
    }
}