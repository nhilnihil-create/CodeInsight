#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
    cin >> a >> b;
 
    if (a < b)
        cout << string(b, a + '0') << "\n";
    else
        cout << string(a, b + '0') << "\n";
 
    return 0;
      
}