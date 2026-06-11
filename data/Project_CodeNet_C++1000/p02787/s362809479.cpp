#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int h, n;
  cin >> h >> n;
  int inf = 1000000009;
  vector<vector<int>> dp(n+1, vector<int>(h+1, inf));
  for(int i=0; i<=n; i++){
    dp[i][0] = 0;
  }
  for(int i=0; i<n; i++){
    int s, t;
    cin >> s >> t;
    for(int j=0; j<=h; j++){
      if(j-s>=0){
        dp[i+1][j] = min(dp[i][j], dp[i+1][j-s]+t);
      }else{
        dp[i+1][j] = min(dp[i][j], dp[i+1][0]+t);
      }
    }
  }
  cout << dp[n][h] << endl;
  return 0;
}
