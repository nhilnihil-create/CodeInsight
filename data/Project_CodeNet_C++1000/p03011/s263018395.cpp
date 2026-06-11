#include <iostream>

using namespace std;

int main(){
  int a,b,c,ans;
  cin >> a >> b >> c;
  ans = min(a+b,b+c);
  ans = min(ans,a+c);
  cout << ans;
}
