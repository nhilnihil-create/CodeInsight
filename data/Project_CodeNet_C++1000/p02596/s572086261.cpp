#include <bits/stdc++.h>
using namespace std;

int main(){
  int K;
  cin >> K;
  int ans=1;
  int an=0;
  for(int i =0; i<K;i++){
    an =(an%K)*10+7;
    if(an%K==0){
      cout << ans << endl;
      break;
    }
    ans++;
  }
  if(an%K!=0){
    cout << -1 << endl;
  }
}
    
      