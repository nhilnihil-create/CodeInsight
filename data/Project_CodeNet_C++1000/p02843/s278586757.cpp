#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
ll MOD = 1000000007;
ll INF =1<<30;

bool dp[100100];
int main(){
   int x;
   cin >> x;
   memset(dp,false,sizeof(dp));
   dp[100] = true;
   dp[0]=true;
   rep(i,100100){
      if(!dp[i]) continue;
      if(dp[i]) {
         dp[i+100]=true;
         dp[i+101]=true;
         dp[i+102]=true;
         dp[i+103]=true;
         dp[i+104]=true;
         dp[i+105]=true;
      }
   }
   if(dp[x])cout << 1<<endl;
   else cout << 0 <<endl;
}