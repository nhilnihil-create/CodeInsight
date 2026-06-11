#include <bits/stdc++.h>
using namespace std;

int main() {
  
long long int a, b, count, ans,A,B;
  ans = 1;
  vector<int> answer(10000);
  cin >> a >> b;
  A =a;
  B =b;

  for(int i = 10001; i > 1; i--){
    if(a % i == 0 && b % i == 0){
      a = a/i;
      b = b/i;
      answer[i] = i;
    }
    
  }
  
  for(int i = 0; i < 10001; i++){
    if(answer[i] != 0){
    ans *= answer[i];

    }
  }

  

  cout << (A*B)/ans<< endl;
  
}
