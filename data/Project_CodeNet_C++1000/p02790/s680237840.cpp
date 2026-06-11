#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  cin >> a >> b;
  int ma=max(a,b);
  int mi=min(a,b);
  for (int X; X<ma; X++){
    cout << mi;
  }
}