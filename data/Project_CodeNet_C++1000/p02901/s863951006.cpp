#include <iostream>
#include <cmath>
#include <climits>

#define KEYMAX 12
#define KEY_POW (int)std::pow(2,KEYMAX)
#define MAX (int)1e3

using namespace std;
typedef long long int ll;
#define INFIN (int)1e9;
int openNum[MAX+1]={};
int value[MAX+1];
ll dp[MAX+1][KEY_POW];
int main(void){
  int N,M;
  cin >> N >> M;
  int total = (int)pow(2,N);
  for(int i=0;i<=M;i++){
    openNum[i] = 0;
  }
  for(int i=1;i<=M;i++){
    int a,b;
    cin >> a >> b;
    value[i] = a;
    for(int j=0;j<b;j++){
      int c,tmp;
      cin >> c;
      tmp = pow(2,c-1);
      openNum[i] += tmp;
    }
  }
  // initialize
  for(int i=0;i<=MAX;i++){
    for(int j=0;j<KEY_POW;j++){
      if(j==0){
        dp[i][0] = 0;
      }else{
        dp[i][j] = INFIN;
      }
    }
  }
  dp[0][0] = 0;
  // dp caliculate
  for(int i=1;i<=M;i++){
    int key = openNum[i];
    int v = value[i];
    //cout << key << " " << v << endl;
    for(int j=0;j<total;j++){
      if(dp[i-1][j] < dp[i][j]){
        //cout << "up" << endl;
        dp[i][j] = dp[i-1][j];
      }
      //cout << "par:" << j << " " << total << endl;
      int opend = j|key;
      int ans = 0;
      int count = 1;
      while(opend > 0){
        if(opend%2 == 1){
          ans = ans + count;
          opend = opend - 1;
        }
        opend /= 2;
        count *= 2;
      }
      //cout << ans << endl;
      if(dp[i-1][j] + v < dp[i][ans]){
        dp[i][ans] = dp[i-1][j] + v;
        //cout << "hit:" << ans << endl;
      }
    }
  }
  ll answer = dp[M][total-1];
  if(answer == (ll)1e9){
    answer = -1;
  }
  cout << answer << endl;
  return 0;
}