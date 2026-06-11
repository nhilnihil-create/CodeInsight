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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(N);
    vector<Pll> pp(N);
    rep(i,N){
        cin >> A[i] >> B[i];
        pp[i] = Pll(A[i],B[i]);
    }
    sort(pp.begin(), pp.end());
    priority_queue<ll> que;
    ll id = 0;
    ll ans = 0;
    REP(i,1,M+1){
        while(id < N && pp[id].fi <= i){
            que.push(pp[id].se);
            id++;
        }
        if(que.empty())continue;
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
}