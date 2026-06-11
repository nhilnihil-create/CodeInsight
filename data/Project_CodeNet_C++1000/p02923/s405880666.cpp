#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b, m = 0, s = 0;
  cin >> n >> b;
  for(int i = 1;i < n;i++) {
    cin >> a;
    if(a > b) {
      if(m < s) m = s;
      s = 0;
    } else {
      s++;
    }
    b = a;
  }
  cout << (m < s ? s : m) << endl;
}