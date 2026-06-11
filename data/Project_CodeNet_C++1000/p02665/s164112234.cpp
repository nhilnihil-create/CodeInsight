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
    ll N;
    cin >> N;
    vector<ll> A(N+1), MA(N+2,1e18);
    rep(i,N+1){
        cin >> A[i];
    }
    MA[0] = 1;
    bool flag = 1;
    rep(i,N+1){
        if(MA[i] - A[i] < 0){
            flag = 0;
            break;
        }
        MA[i+1] = (MA[i] - A[i])*2; 
        if(MA[i+1] > (1e17)){
            break;
        }
    }
    if(!flag){
        cout << -1 << endl;
        return 0;
    }
    vector<ll> v(N+1), b[N+1];
    v[N] = A[N];
    for(ll i=N-1;i>=0;i--){
        v[i] = v[i+1] + A[i];
        v[i] = min(v[i], MA[i]); 
    }
    ll ans = 0;
    REP(i,0,N+1){
        ans += v[i];
    }
    cout << ans << endl;
}