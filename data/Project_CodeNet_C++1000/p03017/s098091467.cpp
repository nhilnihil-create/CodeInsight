#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a,b,c,d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  a--;
  b--;
  c--;
  d--;

  for (int i = a; i < max(c,d); i++)
  {
    if(s[i]=='#' && s[i+1]=='#'){
      puts("No");
      return 0;
    }
  }

  bool ok = true;
  if(d<c){
    ok = false;
    for (int i = b; i <= d; i++)
    {
      if(s[i-1]=='.' && s[i]=='.' && s[i+1]=='.') ok = true;
    }
  }
  if(ok) puts("Yes");
  else puts("No");
}