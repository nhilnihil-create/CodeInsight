#include <iostream>
#include <algorithm>
using namespace std;

struct Item{
  int value, weight;
};

int main(){
  Item items[101];
  int i,j,n,w,dp[102][10002]; 
  cin >> n >> w;
  for( i = 0; i <= 101; i++ ){
    for( j = 0; j <= 10001; j++ ){
      dp[i][j] = 0;
    }
  }

  for( i = 1; i <= n; i++ ) cin >> items[i].value >> items[i].weight;
  
  for( i = 1; i <= n; i++ ){
    for ( j = 1; j <= w; j++ ){
      if( items[i].weight <= j ){
	if ( items[i].value + dp[i-1][j - items[i].weight] > dp[i-1][j] )
	  dp[i][j] = items[i].value + dp[i-1][j - items[i].weight];
	else dp[i][j] = dp[i-1][j];
      }else dp[i][j] = dp[i-1][j];
    }
  }
  cout << dp[n][w] << endl;

  return 0;
}