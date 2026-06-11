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
    vector<deque<ll>> A(N, deque<ll>(N-1));
    rep(i,N){
        rep(j,N-1){
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    bool flag = true;
    ll ans = 0;
    while(flag){
        ans++;
        flag = false;
        vector<ll> memo(N);
        rep(i,N){
            if(memo[i]) continue;
            if(A[i].empty())continue;
            ll t = A[i].front();
            if(memo[t]) continue;
            if(A[t].empty())continue;
            ll u = A[t].front();
            if(i == u){
                flag = true;
                memo[i] = 1;
                memo[t] = 1;
                A[i].pop_front();
                A[t].pop_front();
            }
        }
    }
    rep(i,N){
        if(!A[i].empty()){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans-1 << endl;
}