#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x;
  cin >> x;
  bool h = false;
   for(int i = -150; i <= 150; i++) {
     for(int j = -150; j <= 150; j++) {
       if(pow(i,5) - pow(j,5) == x) {
         cout << i << " " << j << endl;
         h = true;
         break;
      }
       if (h) break;
    }
  }
}