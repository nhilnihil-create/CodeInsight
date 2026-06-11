#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  long long N, A, B;
  cin >> N >> A >> B;

  long long quotient = N / (A + B);
  long long remain = N % (A + B);

  if (remain >= A){
    cout << quotient * A + A << endl;
  }
  else
  {
    cout << quotient * A + remain << endl;
  }
  
}