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

int main(){
    ll H,W;
    cin >> H >> W;
    vector<string> S(H);
    vector<vector<ll>> L(H,vector<ll>(W)), R(H,vector<ll>(W)), U(H,vector<ll>(W)), D(H,vector<ll>(W));
    rep(i,H){
        cin >> S[i];
    }
    rep(i,H){
        ll cnt = 0;
        rep(j,W){
            if(S[i][j] == '.'){
                cnt++;
                L[i][j] = cnt;
            }else{
                cnt = 0;
                L[i][j] = 0;
            }
        }
    }
    rep(i,H){
        ll cnt = 0;
        rep(j,W){
            if(S[i][W-1-j] == '.'){
                cnt++;
                R[i][W-1-j] = cnt;
            }else{
                cnt = 0;
                R[i][W-1-j] = 0;
            }
        }
    }
    rep(j,W){
        ll cnt = 0;
        rep(i,H){
            if(S[i][j] == '.'){
                cnt++;
                U[i][j] = cnt;
            }else{
                cnt = 0;
                U[i][j] = 0;
            }
        }
    }
    rep(j,W){
        ll cnt = 0;
        rep(i,H){
            if(S[H-1-i][j] == '.'){
                cnt++;
                D[H-1-i][j] = cnt;
            }else{
                cnt = 0;
                D[H-1-i][j] = 0;
            }
        }
    }
    ll ans = 0;
    rep(i,H){
        rep(j,W){
            if(S[i][j]=='.'){
                cmax(ans, L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3);
            }
        }
    }
    cout << ans << endl;
}