#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int a,b,c;
  cin >> a;
  string s;
  cin >> s;
  b = s.at(0)-'0';
  c = (s.at(2)-'0')*10 + s.at(3)-'0';
  
  b = b*100+c;
  long long int ans = (a*b)/100;
  cout << ans << endl;
}
