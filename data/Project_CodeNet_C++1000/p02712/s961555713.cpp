#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long S = 0;
  cin >> n;
  for(int i = 1;i < n + 1;i++) {
    if(i % 3 != 0 && i % 5 != 0) S += i;
  }
  cout << S << endl;
}