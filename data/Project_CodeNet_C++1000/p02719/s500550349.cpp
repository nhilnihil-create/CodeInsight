#include <iostream>
using namespace std;
int main(){
  long long n, k;
  cin >> n >> k;
  if(n>k)cout << min(n%k,k-n%k) << endl;
  else cout << min(n, k-n) << endl;
  return 0;
}
