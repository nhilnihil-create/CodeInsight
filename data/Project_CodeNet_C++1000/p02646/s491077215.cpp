#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a , b , v , w , t ;
  cin >> a >> v >> b >> w >> t ;
  long long c = abs(a-b) ;
  
  if(c+w*t<=v*t) cout << "YES" << endl;
  else cout << "NO" << endl;
}