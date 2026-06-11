#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  cin >> K;
  int64_t count = 1;
  int64_t seven = 7;
  bool judge = false;
  for (int i = 0;i < K; i++){
    if (seven % K == 0){
      judge = true;
      break;
    }
    else {
      seven = (seven * 10 + 7) % K;
      count++;
    }
  }
  if (judge == true){
  	cout << count << endl;
  }
  else{
      cout << -1 << endl;
  }
}


