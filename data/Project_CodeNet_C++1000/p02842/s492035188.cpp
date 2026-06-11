#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  double d;
  cin >> N;
  for (int i = 1; i < 50000; i++){
    d = i * 1.08;
    if((int)d == N){
      cout << i;
      return 0;
    }
  }
  cout << ":(";
  return 0;
}
