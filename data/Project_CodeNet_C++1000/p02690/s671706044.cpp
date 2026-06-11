#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t x;
  cin >> x;
  for(int a=0;a<200;a++){
    for(int b=-200;b<200;b++){
      int64_t A=a;
      A*=a*a;
      A*=a*a;
      int64_t B=b;
      B*=b*b;
      B*=b*b;
      if(A-B==x){
        cout << a << " " << b << endl;
        return 0;
      }
    }
  }
}