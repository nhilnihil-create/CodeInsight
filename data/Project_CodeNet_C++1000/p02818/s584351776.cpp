#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long a,b,k,z;
  cin >> a >> b >> k;
  z = 0;
  long long taka = max(a-k,z);
  long long ao = max(b-max(k-a,z),z);
  cout << taka << " " << ao << endl;
}