#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int MAX_N = 400;
const int inf = 1LL << 60;

int dp[MAX_N][MAX_N];
int H[MAX_N],minH[MAX_N];

void chmin(int &a, int b){ if( a > b ){ swap(a,b);} return ;}

signed main(void){ 
  
  int N,K; cin >> N >> K; int m = N-K;
  
  for(int i = 0; i < N; i++){ cin >> H[i];}
  
  minH[0] = H[0];
  
  for(int i = 1; i < N; i++){ 
    minH[i] = min(H[i],minH[i-1]);
  }

  for(int i = 0; i < MAX_N; i++){
    for(int j = 0; j < MAX_N; j++){ 
      dp[i][j] = inf;
    }
  }
  
  dp[0][0] = 0; dp[0][1] = H[0];
  
  for(int i = 0; i < N; i++){ 
    for(int j = 0; j <= i+1; j++){ 
      
      for(int k = 0; k < i; k++){ 
        
        if( j >= 2 ){  // 最後にk番目をちゃんと選んだ場合
          chmin( dp[i][j], dp[k][j-1]+max(0LL, H[i]-H[k]) );
        }
        
        else if( j == 1 ){ //今まで何も選んでいない場合
          chmin( dp[i][j], H[i] );
        } //ここがおかしい　今までから一番小さなものを選ぶはず
          //やっぱりおかしくない
        
        else{ //今回も何も選ばない場合
          chmin( dp[i][0], 0 );
          
        }
      }
    }
  }
  
  int res = inf;
  
  for(int i = m-1; i < N; i++){
  chmin(res, dp[i][m]);
  }

  cout << res << endl;
  
  return 0;
} 
      