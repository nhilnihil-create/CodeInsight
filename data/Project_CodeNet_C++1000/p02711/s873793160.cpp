#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define PI 3.14159265359
using namespace std;

int main(){
  string s;
  bool ans=false;
  cin >> s;
  for(char c : s)if(c=='7')ans=true;
  if(ans)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
