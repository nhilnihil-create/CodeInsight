#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  double T;
  T = N;
  
  if(N % 2 ==0){
    cout << 0.5 << endl;
  } else {
    cout << ((T+1)/2)/T << endl;
  }
}
