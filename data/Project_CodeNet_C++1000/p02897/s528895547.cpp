#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  double n = 0.0;
  if (N % 2 == 0){
    n = N / 2.0;
  }
  else{
    n = (N + 1) / 2.0;
  }
  cout << n / N << endl;
}
  
