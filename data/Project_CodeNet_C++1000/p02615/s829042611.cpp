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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    sort(A.rbegin(), A.rend());
    deque<ll> que;
    //multiset<Pll> ms;
    //me.insert(PlP(A[0],Pll(A[0], A[0]));
    que.push_back(A[0]);
    REP(i,1,N){
        que.push_back(A[i]);
        que.push_back(A[i]);
    }
    ll ans = 0;
    rep(i,N-1){
        ans += que[i];
    }
    cout << ans << endl;
}