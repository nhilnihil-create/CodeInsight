#include <bits/stdc++.h>
 using namespace std;

int main(){
  int X,N;
  int i,res,d;
  bool p[102];
  cin >> X >> N;
  int t;
  for(i=0;i<102;i++)
    p[i] = true;
  for(i=0;i<N;i++){
    cin >> t;
    p[t] = false;
  }

  d = 200;
  res = 0;
    
  for(i=0;i<102;i++){
    if (p[i])
      if (abs(X-i) < d){
        d = abs(X-i);
        res = i;
      }
  }
  
  cout << res << endl;
}