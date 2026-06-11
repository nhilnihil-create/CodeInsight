#include <iostream>
#include <algorithm>
#include <vector>
  

using namespace std;
int main() {
  int a,b;
  cin >> a >> b;
  b = 2*b+1;
  if(a%b==0)cout << a/b;
  else cout <<  a/b + 1;
}
