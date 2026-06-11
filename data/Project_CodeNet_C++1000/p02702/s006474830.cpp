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
    string S;
    cin >> S;
    ll N = S.size();
    vector<ll> dp(N+1),memo(N);
    memo[N-1] = 1;
    for(ll i=N-1;i>=1;i--){
        memo[i-1] = (memo[i]*10)%2019;
    }
    dp[N] = 0;
    map<ll,ll> mp;
    mp[0]++;
    for(ll i=N-1;i>=0;i--){
        ll c = S[i] - '0';
        dp[i] = (c*memo[i] + dp[i+1])%2019;
        mp[dp[i]]++;
    }
    ll ans = 0;
    for(auto& e:mp){
        ans += e.second*(e.second-1)/2;
    }
    cout << ans << endl;
}
