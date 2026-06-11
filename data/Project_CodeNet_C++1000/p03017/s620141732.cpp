#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b, c, d;
  string s;
  bool w = true;
  cin >> n >> a >> b >> c >> d >> s;
  if(c > d) {
    w = false;
    for(int i = b-2;i < d-1;i++) if(s[i]=='.' && s[i+1]=='.' && s[i+2]=='.') w = true;
  }
  for(int i = a;i < min(max(c, d), n-1);i++) if(s[i] == '#' && s[i+1] == '#') w = false;
  cout << (w ? "Yes" : "No") << endl;
}