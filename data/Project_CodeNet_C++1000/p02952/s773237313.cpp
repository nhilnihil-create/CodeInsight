#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int i,ans=0;
  for(i=1;i<=n;i++){
    int s,j;
    s=0;
    j=i;
    while(j>0){
      j /= 10;
      s++;
    }
    if(s%2==1){
      ans++;
    }
  }
  
  cout << ans << endl;
}