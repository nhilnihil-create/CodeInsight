#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, x;
  cin >> k >> x;
  
  int num = x-k;
  for (int i = 1; i < k*2; i++) {
    num++;
    cout << num << " ";
  }
  cout << endl;
}