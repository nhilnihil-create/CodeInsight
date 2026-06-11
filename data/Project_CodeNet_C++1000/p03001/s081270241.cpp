#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long w,h,a,b;
  cin >> w >> h >> a >> b;
  long long ans=(w*h)/2;
  cout << fixed << setprecision(10);
  if(a+a==w&&b+b==h){
    cout << ans << " 1" << endl;
  }
  else{
    if(w%2==0||h%2==0){
      cout << ans << " 0" << endl;
    }
    else{
      cout << ans << ".500000000 0" << endl;
    }
  }
}
