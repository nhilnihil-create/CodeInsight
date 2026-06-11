#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
 
ll MOD = 1000000007;
ll INF =1<<29;
ll dp[100100];
 
int main() {
     int n;
     cin >> n;
     int ans = 0;
     vector<int> a(n),b(n),c(n-1);
     rep(i,n)cin>>a[i];
     rep(i,n) a[i]--;
     rep(i,n) cin>> b[i];
     rep(i,n-1) cin >> c[i];
     rep(i,n) ans +=b[i];
     rep(i,n-1){
         if(a[i+1]==a[i]+1) ans +=c[a[i]];
     }
     cout << ans <<endl;
}