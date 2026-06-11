#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,ans=-1;
  cin >> n >> m;
  for(int i=0;i<=1262;i++){
    if(floor(i*0.08)==n&&floor(i*0.1)==m){
      ans=i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}