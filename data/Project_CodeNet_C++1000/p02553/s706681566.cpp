#include<bits/stdc++.h>
using namespace std;
int main(){
  long long a , b , c , d , w , x , y , z;
  cin >> a >> b >> c >> d;
  w = a*c;
  x = a*d;
  y = b*c;
  z = b*d;
  cout << max(w , max(x , max(y,z))) << endl;
}