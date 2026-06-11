#include <iostream>
#include <string>
using namespace std;
int main() {
  string a, b;
  //scanf("%s %s", &a, &b);
  cin >> a;
  cin >> b;
  int res = 0;
  for(int i = 0; i < 3; i++) {
    if(a[i] == b[i]) res++;
  }
  cout << res;
  return 0;
}
