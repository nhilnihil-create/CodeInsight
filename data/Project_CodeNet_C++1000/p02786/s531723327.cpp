#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin >> N;
  
  int count = 0;
  int64_t ans =1;
  
  while(N/2>0){
    N/=2;
    count ++;
  }
  count ++;
  while(count > 0){
    ans*=2;
    count --;
  }
  
  cout << ans-1 << endl;
  
}