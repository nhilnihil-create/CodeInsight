//According to all known laws of aviation, there is no way that a bee should be able to fly.
//Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway.
//Because bees don't care what humans think is impossible.
#include <bits/stdc++.h>
#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define endl "\n"
using namespace std ;
using bigint = long long int ;
using vi = vector<int> ;
using vll = vector<long long int> ;

int main(){
    int H , W ; cin >> H >> W ;
    char S[H+1][W+1] ;
    for( int i = 0 ; i < H ; i++ ){
        string str ; cin >> str ;
        for( int j = 0 ; j < W ; j++ )
            S[i][j] = str[j] ;
    }
    int left[2001][2001] = { 0 } , right[2001][2001] = { 0 } , up[2001][2001] = { 0 } , down[2001][2001] = { 0 } ;
   for(int i=0; i<H; i++){
      for(int j=0; j<W; j++){
        if(S[i][j]=='.'){
          if(j==0){
            left[i][j] = 1;
          }else{
            left[i][j] = left[i][j-1] + 1;
          }
        }
      }
    }
     for(int i=0; i<H; i++){
      for(int j=W-1; j>=0; j--){
        if(S[i][j]=='.'){
          if(j==W-1){
            right[i][j] = 1;
          }else{
            right[i][j] = right[i][j+1] + 1;
          }
        }
     
      }
     }
     for(int i=0; i<W; i++){
      for(int j=H-1; j>=0; j--){
        if(S[j][i]=='.'){
          if(j==H-1){
            down[j][i] = 1;
          }else{
            down[j][i] = down[j+1][i] + 1;
          }
        }
        
      }
    }
    for(int i=0; i<W; i++){
      for(int j=0; j<H; j++){
        if(S[j][i]=='.'){
          if(j==0){
            up[j][i] = 1;
          }else{
            up[j][i] = up[j-1][i] + 1;
          }
        }
        
      }
    }
    
    int ans = 0 ;
    for( int i = 0 ; i < H ; i++ ){
        for( int j = 0 ; j < W ; j++ ){
            if( S[i][j] != '#' ){
                int T = left[i][j] + right[i][j] + down[i][j] + up[i][j] - 3  ;
                ans = max( ans , T ) ;
            }
        }
    }
    cout << ans << endl ;
    return 0 ;
}
