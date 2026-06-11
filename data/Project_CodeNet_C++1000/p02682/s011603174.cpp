#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, K;
  int count = 0;
  cin >> A >> B >> C >> K;
  if (K - A <= 0)
  {
    cout << K << endl;
  }
  else if (K - A > 0)
  {
    count = A;
    K -= A;
    if (K <= B)
    {
      cout << A << endl;
    }
    else if (K > B)
    {
      K -= B;
      if (K <= C)
      {
        count -= K;
        cout << count << endl;
      }
      else if (K > C)
      {
        count -= C;
        cout << count << endl;
      }
    }
  }
}