#include<bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  double odd = n/2;
  if(n%2 != 0) odd++;
  cout << fixed << setprecision(10);
  cout << odd/n << endl;
}