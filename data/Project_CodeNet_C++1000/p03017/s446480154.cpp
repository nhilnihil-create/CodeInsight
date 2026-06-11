#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  
  bool ok = true, over = false, three = false;
  if((a < b && c > d) || (a > b && c < d)) over = true;
  int l = s.size();
  if(a > b) swap(a, b);
  if(c > d) swap(c, d);
  for(int i = a; i < d-1; i++){
    if(s.at(i) == '#' && s.at(i+1) == '#') ok = false;
    if(i >= b-2 && i < c-1){
      if(s.at(i) == '.' && s.at(i+1) == '.' && s.at(i+2) == '.') three = true;
    }
  }
  
  if(over){
    if(!three) ok = false;
  }
  
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}