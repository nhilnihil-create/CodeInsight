#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int K, A, B;
  cin >> K >> A >> B;
  
  string s = "NG";
  
  for (int i = A; i <= B; i++)
  {
    if (i % K == 0)
    {
      s = "OK";
      break;
    }
  }
  
  cout << s << endl;
}