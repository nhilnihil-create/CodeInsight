#include <iostream>
#include <vector>
using namespace std;
int main(){
  long long N;
  cin >> N;
  if(N % 2 == 1) cout << 0 << endl;
  else{
    long long temp = N / 2;
    long long t = 5;
    long long ans = 0;
    while(temp / t / 5 > 0){
      ans += temp / t;
      t *= 5;
    }
    ans += temp / t;
    cout << ans << endl;
  }
}