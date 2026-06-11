#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll X;
  cin >> X;
  
  ll A, B;
  for (ll A = 120; A > -120; A--)
  {
    for (ll B = A; B > -120; B--)
    {
      ll temp = (ll)pow(A, 5) - (ll)pow(B, 5);
      if (temp == X)
      {
        cout << A << " " << B << endl;
        return 0;
      }
      if (temp > X)
      {
        break;
      }  
    }
    
  }
  
  return 0;
}
