#include <iostream>
using namespace std;

int main(){

  long long a,b,k;
  cin >> a >> b >> k;
  
  k-=a;
  a=max((long long)0,-k);
  b=max((long long)0,b-max(k,(long long)0));
  
  cout << a << ' ' << b << endl;
  return 0;
}