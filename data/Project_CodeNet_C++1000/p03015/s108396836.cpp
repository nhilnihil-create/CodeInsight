#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <fstream>
#include <chrono>
#include <random>
#include <bitset>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size())
#define pb push_back
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
const ll mod = 1000000007;

int main(){
  string L; cin >> L;
  int N = sz(L);
  // dp[i][smaller?] i桁決めて条件を満たす(a,b)
  ll dp[101000][2];
  dp[0][0] = 1;
  rep(i,N){
    if(L[i]=='0'){
      dp[i+1][1] = dp[i][1]*3;
      dp[i+1][0] = dp[i][0];
    }
    if(L[i]=='1'){
      dp[i+1][1] = dp[i][0] + dp[i][1]*3;
      dp[i+1][0] = dp[i][0]*2;
    }
    dp[i+1][0]%=mod;
    dp[i+1][1]%=mod;
  }
  cout << (dp[N][0]+dp[N][1])%mod << endl;
  return 0;
}
