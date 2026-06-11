#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
double n;

int main(void){
  cin >> n;
  for(int i = 1; i <= 50000; i++){
    if(abs(floor(1.08*i) - n) < eps){
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
  return 0;
}
