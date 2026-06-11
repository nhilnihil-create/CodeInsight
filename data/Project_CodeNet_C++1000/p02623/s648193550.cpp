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
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N), B(M), AS(N+1), BS(M+1);
    rep(i,N){
        cin >> A[i];
    }
    ll sum = 0;
    rep(i,M){
        cin >> B[i];
        sum += B[i];
    }
    ll j = M-1;
    ll ans = 0;
    rep(i,N+1){
        while(j >= 0 && sum > K){
            sum -= B[j];
            j--;
        }
        if(sum <= K){
            cmax(ans, j+1+i);
        }
        if(i==N)break;
        sum += A[i];
    }
    cout << ans << endl;
}