#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  long long a,b,c,d;
  cin >> a >> b >> c >> d;
  long long K = max(max(a*c,a*d),max(b*c,b*d)) ;
  cout << K << endl;
  
}