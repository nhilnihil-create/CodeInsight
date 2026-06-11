#include<bits/stdc++.h>
using namespace std;

int main(){
  int m,d,d1,d2,ans=0,i,j;
  cin >> m >> d;
  for(j=1; j<=m; j++){
  for(i=22; i<=d; i++){
    d1=i/10; d2=i%10;
    if(j==d1*d2 && d2>=2){
      ans++;
    }
  }
    
  }
  cout << ans;
}