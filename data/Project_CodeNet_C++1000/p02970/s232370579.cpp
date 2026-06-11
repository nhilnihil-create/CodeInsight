#include <bits/stdc++.h>
using namespace std;
#define rep(i,A) for(int i = 0;i < A;i++)

int main() {
  int A,B;
  cin >> A >> B;
  if(A % (2 * B + 1) == 0){
    cout << A / (2 * B + 1) << endl;
  }
  else{
    cout << A / (B * 2 + 1) + 1 << endl;
  }

  
}
