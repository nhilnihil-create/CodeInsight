#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
int a[3][3],n;
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;

int gcd(int a,int b){
	if (a%b == 0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}

}
int lcm(int a,int b){
	return a /gcd(a,b) * b;
}







int main() {
  string S;
  cin >> S;
  set<string> s;
  int n = S.length();
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  if (n == 2) {
    if (S[0] == S[1]) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
    return 0;
  }
 
  int dp[n]{};
  // 1文字目
  dp[0] = 1;
  // 2文字目
  if (S[0] == S[1]) {
    dp[1] = 1; // aa -> a, a
  } else {
    dp[1] = 2; // ab -> a, b
  }
  // 3文字目
  if (S[0] != S[1] && S[1] != S[2]) {
      dp[2] = 3; // aba -> a, b, a
  } else {
      dp[2] = 2; // ?aa -> ?a, a
  }
  for (int i = 3; i < n; i++) {
      if (S[i - 1] == S[i]) {
          dp[i] = dp[i - 3] + 2; // ??aa -> ?, ?a, a or ?, ?, aa
      } else {
          dp[i] = dp[i - 1] + 1; // ?ab -> ?, a, b or ?a, b
      }
  }
  cout << dp[n - 1] << "\n";
  return 0;
}