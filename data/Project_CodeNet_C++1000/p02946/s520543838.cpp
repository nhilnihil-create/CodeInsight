#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, x;
  cin >> n >> x;
  int a = x-n+1;
  int b = 2*n-1+a;
  for(int i=a; i<b; i++) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}