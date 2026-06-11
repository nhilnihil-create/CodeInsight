#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll x;
  cin >> x;
  
  ll def = 100;
  int count = 0;
  while(true) {
    if(x > def) {
      count++;
      def += def/100;
    }
    else break;
  }
  cout << count << endl;
}