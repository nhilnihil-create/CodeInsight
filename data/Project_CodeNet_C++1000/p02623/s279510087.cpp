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
        //AS[i+1] = AS[i] + A[i];
    }
    rep(i,M){
        cin >> B[i];
        //BS[i+1] = BS[i] + B[i];
    }
    ll sum = 0;
    ll id = 0;
    while(id < N && sum + A[id] <= K){
        sum += A[id];
        id++;
    }
    ll r = 0;
    ll ans = 0;
    for(ll l=id-1;l>=-1;l--){
        while(r < M && sum + B[r] <= K){
            sum += B[r];
            r++;
        }
        if(sum <= K){
            cmax(ans, l+1+r);
        }
        sum -= A[l];
    }
    cout << ans << endl;
}