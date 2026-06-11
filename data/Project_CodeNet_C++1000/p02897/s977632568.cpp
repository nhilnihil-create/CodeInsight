#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int n;
  cin >> n;
  if(n%2==0) cout << 0.5 << "\n";
  else if(n==1) cout << 1 << "\n";     
  else cout << ceil((double)n/2)/n << "\n";
  return 0;
}