#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int A,B,N;
  cin >> A >> B >> N;
  if(B>N){
    cout << (A*N)/B-(A*(N/B)) << endl;
    return 0;
  }
  else{
    int x = N-(N%B)-1;
    cout << (A*x)/B-(A*(x/B)) << endl;
    return 0;
  }
}
