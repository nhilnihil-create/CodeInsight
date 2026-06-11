#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t n , k ,c;
  cin >> n >>k;
  c=n%k ; 
  cout << min ( c , k-c) << endl;
}