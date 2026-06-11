#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}

int main(void){
  int n, g, ans=0;
  
  cin >> n;
  for (int a=1; a<=n; a++){
    for (int b=1; b<=n; b++){
      g = gcd(a,b);
      for (int c=1; c<=n; c++){
        ans += gcd(g,c);
      }
    }
  }
  cout << ans << endl;
  return 0;
}