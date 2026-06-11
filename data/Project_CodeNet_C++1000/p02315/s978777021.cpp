#include<bits/stdc++.h>
using namespace std;

// 入力
int n, W;
int w[100], v[100];

int dp[101][10001];


int rec_dp(int i, int j) {
  if (dp[i][j] != -1) {

    return dp[i][j];
  }

  int res;
  if (i == n) {
 
    res = 0;
  } else if (j < w[i]) {

    res = rec_dp(i + 1, j);
  } else {
   
    int r[2]={rec_dp(i + 1, j),
              rec_dp(i + 1, j - w[i]) + v[i],
	      /*   rec_dp(i,j-w[i])+v[i]*/};
    sort(r,r+2);
    res=r[1];
    
  }

  return dp[i][j] = res;
}

int main() {
  memset(dp, -1, sizeof(dp)); // メモ化テーブルを-1で初期化　以下のforループと等価


  cin>>n>>W;
  for(int i=0;i<n;i++){
    cin>>v[i]>>w[i];
  }
  cout << rec_dp(0, W) << endl;
}