#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int H,W;
  cin >> H >> W;
  string S[H];
  for(int i=0;i<H;i++){
    cin >> S[i];
  }
  int L[H][W],R[H][W],D[H][W],U[H][W];
  for(int n=0;n<H;n++){
    for(int m=0;m<W;m++){
      if(S[n][m]=='#'){
	L[n][m]=0;
      }else if(m==0){
	L[n][m]=1;
      }else {
	L[n][m]=L[n][m-1]+1;
      }
      if(S[H-1-n][W-1-m]=='#'){
	R[H-1-n][W-1-m]=0;
      }else if(m==0){
	R[H-1-n][W-1-m]=1;
      }else {
	R[H-1-n][W-1-m]=R[H-1-n][W-m]+1;
      } 
    }
  }
  for(int m=0;m<W;m++){
    for(int n=0;n<H;n++){
      if(S[n][m]=='#'){
	D[n][m]=0;
      }else if(n==0){
	D[n][m]=1;
      }else {
	D[n][m]=D[n-1][m]+1;
      }
      if(S[H-1-n][W-1-m]=='#'){
	U[H-1-n][W-1-m]=0;
      }else if(n==0){
	U[H-1-n][W-1-m]=1;
      }else {
	U[H-1-n][W-1-m]=U[H-n][W-1-m]+1;
      }
    }
  }
  int ans = 0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      ans=max(ans,L[i][j]+R[i][j]+D[i][j]+U[i][j]-3);
    }
  }
  cout << ans << endl;
}
