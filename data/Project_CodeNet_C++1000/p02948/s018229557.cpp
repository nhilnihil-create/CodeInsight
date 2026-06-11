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
    vector<vector<ll>> v(M+1);
    priority_queue<ll> que;
    rep(i,N){
        cin >> A[i] >> B[i];
        if(A[i] > M) continue;
        v[A[i]].push_back(B[i]);
        //que.push(Pll(B[i],A[i]));
    }
    ll ans = 0;
    rep(i,M){
        ll d = i+1;
        for(auto& u:v[d]){
            que.push(u);
        }
        if(que.empty())continue;        
        ll t = que.top();
        //ll t = que.top().first;
        //ll d = que.top().second;
        que.pop();
        ans += t;
    }
    cout << ans << endl;
}