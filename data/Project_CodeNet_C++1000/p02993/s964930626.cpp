
#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
int main(){
  string s;
  std::cin >> s;
  bool ok=true;
  for (int i = 1; i < 4; i++) {
    if(s[i]==s[i-1])ok=false;
  }
  if(ok)std::cout << "Good" << '\n';
  else std::cout << "Bad" << '\n';




  return 0;
}
