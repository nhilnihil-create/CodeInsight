#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  string s(a,'0'+b);
  string t(b,'0'+a);
  cout << min(s,t) << endl;
}
