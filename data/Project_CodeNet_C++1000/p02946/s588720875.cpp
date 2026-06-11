#include <bits/stdc++.h>
using namespace std;
int main() {
  int k,x;
  cin >> k >> x;
  int s = x-k+1;
  int f = s + k*2-1;
  for(int i=s; i<f; i++) {
    cout << i << " ";
  }
  cout << endl;
}