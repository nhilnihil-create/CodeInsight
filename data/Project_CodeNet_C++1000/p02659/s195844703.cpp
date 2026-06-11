#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int a,b,c;
  cin >> a;
  string s;
  cin >> s;
  s.erase(1,1);
  b = stoi(s);
  long long int ans = (a*b)/100;
  cout << ans << endl;
}
