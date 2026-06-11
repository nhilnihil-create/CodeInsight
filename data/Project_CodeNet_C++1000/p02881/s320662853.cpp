#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
  long long int N;
  
  cin >> N;
  
  long long int ans = N + 1;
  for(int i = 1;i <= sqrt(N);i++) if(N % i == 0) ans = min(ans, (N/i + i));
  
  cout << ans - 2 << endl;
  
  return 0;
}