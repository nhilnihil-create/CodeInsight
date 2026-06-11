#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cout.setf(ios::fixed); cout.precision(17);
    
  long long a, b, c;
  cin >> a >> b >> c;
  long long x = c - a - b;
  long long y = 4 * a * b;
  if(x > 0 && x * x > y)
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}
