#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,d;
  cin >> n >> d;
  if (n % (2*d + 1) == 0){
    cout << n/(2*d + 1) << endl;
  }
  else{
    cout << n/(2*d + 1) + 1 << endl;
  }
}