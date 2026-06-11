#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  long long K, A, B;
  cin >> A >> B >> K;

  if (A >= K){
    cout << A - K << ' ' << B << endl;
  }
  else if (B >= K - A)
  {
    cout << 0 << ' ' << B - K + A << endl;
  }
  else
  {
    cout << 0 << ' ' << 0 << endl;
  }
  
  
  
}