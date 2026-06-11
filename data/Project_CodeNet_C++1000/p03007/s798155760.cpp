#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
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
    ll N;
    cin >> N;
    vector<ll> A(N),v,u;
    rep(i,N){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    deque<ll> que;
    rep(i,N){
        que.push_back(A[i]);
    }
    ll M = que.back();
    que.pop_back();
    ll m = que.front();
    que.pop_front();
    rep(i,N-2){
        ll t = que.back();
        que.pop_back();
        if(t<=0){
            v.push_back(M);
            u.push_back(t);
            M -= t;
        }else{
            v.push_back(m);
            u.push_back(t);
            m -= t;
        }
        /*
        if(!(i%2)){
            ans += que.back();
            que.pop_back();
        }else{
            ans -= que.front();
            que.pop_front();
        }*/
    }
    v.push_back(M);
    u.push_back(m);
    cout << M-m << endl;
    rep(i,N-1){
        cout << v[i] << " " << u[i] << endl;
    }
}