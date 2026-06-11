#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  int A, B;
  cin >> K >> A >> B;
  int n=B % K;
  if(B-n >= A)
    cout << "OK" << endl;
  else
    cout << "NG" << endl;
}
