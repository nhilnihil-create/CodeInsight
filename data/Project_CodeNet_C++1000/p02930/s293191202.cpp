#include<bits/stdc++.h>
using namespace std;
int ans[513][513] = {};
int main(){
  int n;
  cin >> n;
  int level = 0;
  int pw2 = 1;
  for(int j=0; j<502; j++){
    while(pw2<=j){
      pw2*=2;
      level++;
    }
    for(int i=0; i<pw2; i++){
      if(i<pw2/2) ans[i][j] = level;
      else ans[i][j] = ans[i-pw2/2][j-pw2/2];
    }
  }
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}
