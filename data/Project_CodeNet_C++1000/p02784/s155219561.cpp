#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c;
  int count=0;
  cin >> a >> b;
  for(int i=0;i<b;i++){
   cin >> c;
   count += c;
  }
  if(a>count) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
