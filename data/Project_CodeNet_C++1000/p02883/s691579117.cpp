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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N), F(N);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        cin >> F[i];
    }
    sort(A.begin(), A.end());
    sort(F.rbegin(), F.rend());
    
    ll L = -1;
    ll R = 1e12+1;
    while(L+1 < R){
        ll X = (L + R)/2;
        bool flag = true;
        ll cnt = 0;
        rep(i,N){
            ll t = A[i] * F[i];
            if(t > X){
                cnt += ((t-X)+F[i]-1)/F[i];
                if(cnt > K){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            R = X;
        }else{
            L = X;
        }
    }
    cout << R << endl;
}