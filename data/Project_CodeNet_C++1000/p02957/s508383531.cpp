#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b;cin>>a>>b;
  if (a%2 != b%2) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  long long d = (a+b)/2;
  int e = max(a,b) - min(a,b);
  if (a>=d && b>=d) {
    cout << min(a,b) + e/2 << endl;
  } else {
    cout << d << endl;
  }

}
