#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a,d,c;
  cin >> a >> d >> c;
  a = abs(a);
  long long step = min(d,a/c);
  d -= step;
  a -= step*c;
  if (d%2==0)cout << a << endl;
  else cout << c-a << endl;
}