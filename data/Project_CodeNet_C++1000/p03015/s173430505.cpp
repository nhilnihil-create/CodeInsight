#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

string s;

int main(){
  cin >> s;
  bool flag;
  ll ans;
  ll dp[100000][2];
  dp[0][0] = 1; dp[0][1] = 2;
  for(int i = 1; i < s.size(); i++){
    int k = s.at(i) - '0';
    if(k){
      dp[i][0] = (dp[i-1][0] * 3 + dp[i-1][1] * 1 )% MOD;
      dp[i][1] = 2*dp[i-1][1] % MOD;
    }else{
      dp[i][0] = dp[i-1][0] * 3 % MOD;
      dp[i][1] = dp[i-1][1];
    }
  }
  cout << (dp[s.size()-1][0] + dp[s.size() - 1][1]) % MOD<<endl;
}
    