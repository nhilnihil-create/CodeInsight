#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, c = 0;
  cin >> n;
  for(int i = 0;i < n;i++) {
    int a;
    cin >> a;
    if(((i+1) * a) % 2 == 1) c++;
  }
  cout << c << endl;
}