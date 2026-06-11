#include <bits/stdc++.h>
using namespace std;
int main(){
 string S;
  int Q;
  cin >> S >> Q;
  bool isreverse = false;
  
  for(int i=0;i<Q;i++){
    int T;
    cin >> T;
    if(T==1&&isreverse) isreverse = false;
    else if(T==1&&!isreverse) isreverse = true;
    
    if(T==2){
      int F;
      string s;
      cin >> F >> s;
      
      if(F==1&&isreverse) S += s;
      if(F==1&&!isreverse) S.insert(0,s);
      if(F==2&&isreverse) S.insert(0,s);
      if(F==2&&!isreverse) S += s;
    }
  }
  
  if(isreverse) reverse(S.begin(),S.end());
  
  cout << S << endl;
  return 0;
}