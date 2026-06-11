#include <bits/stdc++.h>
using namespace std;

int main(){
  int M,D,ans=0;
  cin >> M >> D;
  for(int j=1;j<M+1;j++){
  for(int i=11;i<D+1;i++){
    if((i/10)*(i%10)==j){
      if(i/10>1&&i%10>1) ans++;
    }
  }
  }
  cout << ans << endl;
}