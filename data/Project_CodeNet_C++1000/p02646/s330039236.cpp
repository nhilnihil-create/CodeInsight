#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a,v,b,w,t;
  cin >> a >> v >> b >> w >> t;

  long long dis = abs(b - a);
  long long ver = w - v;

  // if(ver == 0) {
  //   if(dis == 0) cout << "YES" << endl;
  //   else cout << "NO" << endl;
  //   return 0;
  // }

  // if(ver < 0 && dis / abs(ver) <= t){
  if(ver < 0 && dis <= t * abs(ver)){
    cout << "YES" << endl;
  }else cout << "NO" << endl;
  
  return 0;
}