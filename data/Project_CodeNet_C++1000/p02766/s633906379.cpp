#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int c = 0;
  long long t = 1;
  while (n >= t) {
    c++;
    t *= k;
  }
  cout << c << endl;
}
