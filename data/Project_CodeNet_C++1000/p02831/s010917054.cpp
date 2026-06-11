#include <bits/stdc++.h>
using namespace std;

int main(){
  long long A,B;
  cin >> A >> B;
  for (long long i = 1; i< B+1 ;i++){
    if (A * i % B == 0){
      cout << i*A;
      break;
    }
  }
}
    