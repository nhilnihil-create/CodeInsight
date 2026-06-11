#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  string s; cin>>s;
  bool ans=true;
  rep(i, s.size()) {
    if(i%2==0) {
      if(s.at(i)!='R'&&s.at(i)!='U'&&s.at(i)!='D') ans=false;
    }
    else {
      if(s.at(i)!='L'&&s.at(i)!='U'&&s.at(i)!='D') ans=false;
    }
  }
  
  if(ans==true) cout << "Yes";
  else cout << "No";
}