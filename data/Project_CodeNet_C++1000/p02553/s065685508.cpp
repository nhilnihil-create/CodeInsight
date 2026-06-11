#include <iostream>
using namespace std;

int main(){
  long a, b, c, d, n1, n2, n3, n4;
  cin >> a >> b >> c >> d;
  n1 = a*c;
  n2 = a*d;
  n3 = b*c;
  n4 = b*d;
  long max = n1;
  if(max<n2){ max=n2; }
  if(max<n3){ max=n3; }
  if(max<n4){ max=n4; }
  cout << max;
  return 0;
}
  