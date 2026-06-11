#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a[3][3],n;
  for ( int i=0; i<3 ; i++){
    for (int j=0 ; j<3 ; j++){
      cin >> a[i][j];
    }
  }
  cin >> n;
  int b[n] ;
  for ( int i= 0 ; i<n ; i++) {
    cin >> b[i] ;
  }
  bool c[3][3];
   for ( int i=0; i<3 ; i++){
    for (int j=0 ; j<3 ; j++){
      c[i][j]=false ;
      for ( int k = 0 ; k<n ; k++){
      if ( a[i][j]==b[k]){
        c[i][j]=true ;
      }
      }
    }
  } 
  string ans="No" ; 
  for ( int i=0 ; i<3 ; i++){
    if ( c[i][1] && c[i][2]&&c[i][0]){
      ans= "Yes" ;
    }
    if ( c[0][i] && c[1][i]&&c[2][i]){
      ans= "Yes" ;
    }
  }
    if ( c[0][0] && c[1][1]&&c[2][2]){
      ans= "Yes" ;
    }
    if ( c[0][2] && c[1][1]&&c[2][0]){
      ans= "Yes" ;
    }
    cout << ans << endl;
  
}