#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  cin >> A >> B;
  if (A - B * 2 < 1)
  {
    cout << 0 << endl;
  }
  else
  {
    cout << A - B * 2 << endl;
  }
}