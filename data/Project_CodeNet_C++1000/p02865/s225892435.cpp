#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(void){
  int n;
  cin >> n;
  if (n%2==0) cout << n/2-1 << endl;
  else cout << (n-1)/2 << endl;
  return 0;
}