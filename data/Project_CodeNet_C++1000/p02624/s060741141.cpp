#include<iostream>
#include<cmath>
using namespace std;
int main(void){
  __int64_t num,p;
  __int64_t ans = 0;
  cin >> num;
  for(int i = 1;i <= num;i ++){
    p = floor(num/i);
    p = i*p*(p+1)/2;
    ans = ans+p;
  }
  cout << ans << endl;
  
  return 0;
}