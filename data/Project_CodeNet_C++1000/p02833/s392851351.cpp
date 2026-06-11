#include <bits/stdc++.h>
using namespace std;

int main(){
  unsigned long long int N, ans = 0;
  //unsigned long long int test = 1;
  cin >> N;
  
  /*for (int i = N; i > 0; i -= 2){
    test *= i;
  }
  cout << test << endl;*/
  
  if (N % 2 == 1){
    cout << "0" << endl;
  }
  else{
    N /= 2;
    
    while (N >= 5){
      N /= 5;
      ans += N;
    }
  
    cout << ans << endl;
  }
}