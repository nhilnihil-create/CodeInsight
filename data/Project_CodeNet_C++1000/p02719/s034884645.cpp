#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n,k;
  cin >> n >> k;
  
    if( n % k == 0 )
      cout << 0 << endl;
    else if(n < k)
      cout << min( abs(n-k),n ) << endl;
    else {
      n %= k;
      cout << min( abs(n-k),n ) << endl; 
    }
}