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
    vector<ll> A(N+1);
    rep(i,N+1){
        cin >> A[i];
    }
    vector<ll> M(N+2);
    M[0] = 1;
    rep(i,N+1){
        if(A[i] > M[i]){
            cout << -1 << endl;
            return 0;
        }
        M[i+1] = M[i] - A[i];
        M[i+1] *= 2;
        if(M[i+1] > 1e18){
            REP(j,i,N){
                M[j+1] = 1e18;
            }
            break;
        }
    }
    //ll leaves = A[N];
    ll brus = 0;
    ll ans = 0;
    for(ll i=N;i>=0;i--){
        ans += A[i];
        brus = min(brus, M[i]-A[i]);
        ans += brus;
        brus = (A[i]+brus);
    }
    cout << ans << endl;
}