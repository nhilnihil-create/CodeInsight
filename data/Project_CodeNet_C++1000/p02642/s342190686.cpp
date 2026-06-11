#include <bits/stdc++.h>
//#include <atcoder/all>
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
//using namespace atcoder;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N), B(1000001,0), memo(1000001,0), C;
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        memo[A[i]]++;
    }
    ll ans = 0;
    rep(i,N){
        if(memo[A[i]] > 1){
            memo[A[i]]--;
            B[A[i]]++;
            continue;
        }
        C.push_back(A[i]);
    }
    /*
    if(memo[1] > 1){
        rep(i,N){
            if(A[i] == 1) continue;
            C.push_back(A[i]);
        }
    }else{
        C = A;
    }*/
    N = C.size();
    rep(i,N){
        ll cur = C[i];
        while(cur <= 1000000){
            B[cur]++;
            cur += C[i];
        }
    }
    rep(i,N){
        if(B[C[i]] == 1){
            ans++;
        }
    }
    cout << ans << endl;
}