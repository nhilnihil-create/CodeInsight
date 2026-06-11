#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long int x;
  cin >> x;
  
  if(x <= 599) cout << 8 << endl;
  else if(799 >= x) cout << 7 << endl;
  else if(999 >= x) cout << 6 << endl;
  else if(1199 >= x) cout << 5 << endl;
  else if(1399 >= x) cout << 4 << endl;
  else if(1599 >= x) cout << 3 << endl;
  else if(1799 >= x) cout << 2 << endl;
  else cout << 1 << endl;
}