#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

int main() {
  int n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  bool ok = false;
  s = '#' + s + '#';
  
  if(c<=d) ok=true;
  else {
    srep(i,b,d+1) {
      if(s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.') ok=true;
    }
  }

  srep(i,a-1,c) {
    if(s[i]=='#'&&s[i+1]=='#') ok=false;
  }
  srep(i,b-1,d) {
    if(s[i]=='#'&&s[i+1]=='#') ok=false;
  }

  cout << (ok? "Yes" : "No") << endl;
  return 0;
}