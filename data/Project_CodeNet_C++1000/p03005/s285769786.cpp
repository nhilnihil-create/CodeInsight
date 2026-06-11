#include <iostream>

using namespace std;

int main(void){
  int n,k;
  cin >> n >> k;
  int ans;
  if(k > 1)
	ans = (n - k);
  else
    ans = 0;
  cout << ans;
  return 0;
}