#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s, t;
  cin >> s >> t;
  int slen = s.size();
  int tlen = t.size();
  int c = 0, m = 0;
  for(int i = 0; i <= slen - tlen; i++){
    for(int j = 0; j < tlen; j++){
    	if(s[j + i] == t[j])
          c++;
    }
    m = max(m, c);
    c = 0;
  }
  cout << tlen - m << '\n';
}