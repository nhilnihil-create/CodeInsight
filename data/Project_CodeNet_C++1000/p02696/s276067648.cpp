#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long a,b,n,x;
  cin >> a >> b >> n;
  x = min(b-1,n);
  cout << a*x/b << endl;
}
