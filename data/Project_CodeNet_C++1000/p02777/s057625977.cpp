#include<bits/stdc++.h>
using namespace std;
int main()
{
string S,T,U;
 int a,b;
  cin >> S >> T >> a >> b >> U;
  
  if(S==U) cout << a-1 << ' ' << b;
  else cout << a << ' ' << b-1;


return 0;
}