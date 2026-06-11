#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,c,k;
  cin >> a >> b >> c >> k;
  long long ans = 0;
  if(k <= a) cout << k << endl;
  else if(k <= a + b) cout << a << endl;
  else cout << a - (k - a - b) << endl;
}