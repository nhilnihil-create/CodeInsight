#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



int main() {
    ll H,N;
    cin >>H>>N;
    vector<ll> A(N);
    vector<ll> B(N);
    rep(i,N){
        cin >>A[i]>>B[i];
    }
    vector<vector<ll>> dp(N+1,vector<ll>(20015,INF));
    rep(i,N){
        dp[i][0] =0;
    }
    rep2(i,N){
        rep(j,20010){
            if(j-A[i-1] >= 0){
                dp[i][j] = min({dp[i-1][j], dp[i-1][j-A[i-1]]+B[i-1], dp[i][j-A[i-1]]+B[i-1]});
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    ll ans = INF;
    rep3(i,H,20010){
        chmin(ans,dp[N][i]);
    }
    cout << ans << endl;


    return 0;
    

}