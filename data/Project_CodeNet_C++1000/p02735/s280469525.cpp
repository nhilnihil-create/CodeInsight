#include<bits/stdc++.h>
using namespace std;
#define int long long 

char table[110][110];

const int inf = 1010;

void chmin(int &a, int b){ 
  if( a > b ){ swap(a,b);}
  return ;
}

signed main(void){ 
  
  int h,w; cin >> h >> w;
  
  vector<vector<int>> dp(h,vector<int>(w,inf));
  dp[0][0] = 0;
    
  for(int i = 0; i < h; i++){ 
    for(int j = 0; j < w; j++){ 
      
      cin >> table[i][j];
      
    }
  }
  
  for(int i = 0; i < h; i++){ 
    for(int j = 0; j < w; j++){ 
      
      if( i < h-1 ){ 
        
        int c = ( table[i][j] == '.' && table[i+1][j] == '#' );
        
        chmin(dp[i+1][j],dp[i][j]+c);
        
      }
      
      if( j < w-1 ){ 
        
        int c = ( table[i][j] == '.' && table[i][j+1] == '#' );
        
        chmin(dp[i][j+1],dp[i][j]+c);
        
      }
      
    }
  }
  
  int d = (table[0][0] == '#' );
  
  cout << dp[h-1][w-1]+d << endl;
  
  return 0;
  
} 
    