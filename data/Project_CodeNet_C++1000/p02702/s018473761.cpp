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
    string S;
    cin >> S;
    N = S.size();
    vector<ll> dp(N+10),dec(N+10);
    ll t = 1;
    rep(i,N){
        dec[N-1-i] = t;
        t *= 10;
        t %= 2019;
    }
    ll cur = 0;
    dp[N] = 0;
    rep(i,N){
        ll c = S[N-1-i] - '0';
        cur += c*dec[N-1-i];
        cur %= 2019;
        //if(!(cur)){
        //    dp[N-1-i] = ;//dp[N-i] + 1;
        //}else{
        dp[N-1-i] = cur;//dp[N-i];
        //cout << cur << endl;
        //}
    }
    ll sum = 0;
    map<ll,ll>mp;
    rep(i,N+1){
        mp[dp[i]]++;
    }
    ll ans = 0;
    for(auto& e:mp){
        //cout << e.second << endl;
        ans += e.second*(e.second-1)/2;
    }
    cout << ans << endl;
}