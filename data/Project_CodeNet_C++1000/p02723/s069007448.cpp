#include <bits/stdc++.h>
#define rep(i,n) for(int i=1; i<=(n); ++i)
#define PI 3.14159265359
using namespace std;
using ll = long long;

int main(){
  string s;
  cin >> s;
  bool ans=false;
  if(s[2]==s[3] && s[4]==s[5]) ans=true;
  cout << (ans?"Yes":"No") << endl;
  return 0;
}
