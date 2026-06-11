#include<bits/stdc++.h>
using namespace std;

int main() {
  int K,A,B;
  cin >> K >> A >> B;
  if(A/K<B/K||A%K==0||B%K==0) {
    cout << "OK" << endl;
  } else {
    cout << "NG" << endl;
  }
}