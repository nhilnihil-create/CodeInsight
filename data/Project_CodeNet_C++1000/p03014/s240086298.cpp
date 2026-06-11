#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;



int main(){
  int h,m;
  cin >>h >>m;
  int L[h][m]={},R[h][m]={},U[h][m]={},D[h][m]={};
  char a[h][m];
  rep(i,h){
    rep(ii,m)cin >> a[i][ii];
  }
  rep(i,h){
    rep(ii,m){
      if(a[i][ii]=='#'){
        R[i][ii]=0;
      }else{
        if(ii>0){R[i][ii]=R[i][ii-1]+1;}else{R[i][ii]=1;}
      }

      if(a[i][m-ii-1]=='#'){
        L[i][m-ii-1]=0;
      }else{
        if(m-ii<m){L[i][m-ii-1]=L[i][m-ii]+1;}else{L[i][m-ii-1]=1;}
      }
    }
  }
  rep(ii,m){
    rep(i,h){
      if(a[i][ii]=='#'){
        D[i][ii]=0;
      }else{
        if(i>0){D[i][ii]=D[i-1][ii]+1;}else{D[i][ii]=1;}
      }

      if(a[h-i-1][ii]=='#'){
        U[h-i-1][ii]=0;
      }else{
        if(h-i<h){U[h-i-1][ii]=U[h-i][ii]+1;}else{U[h-i-1][ii]=1;}
      }
    }
  }
  int ans=0;
  rep(i,h){
    rep(ii,m){
      int g=L[i][ii]+R[i][ii]+U[i][ii]+D[i][ii]-3;
      chmax(ans,g);
    }
  }
  cout << ans << endl;
}