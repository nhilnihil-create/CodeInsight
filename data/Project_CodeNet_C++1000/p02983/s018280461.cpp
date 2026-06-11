#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t n,m;
  cin >> n >> m;
  int64_t ans=2018;
  if(m-n>2019){
    ans=0;
  }else{
    for(int64_t i=n;i<m;i++){
      for(int64_t j=i+1;j<=m;j++){
        ans=min((i*j)%2019,ans);
      }
    }
  }
  cout << ans << endl;
  return 0;
}