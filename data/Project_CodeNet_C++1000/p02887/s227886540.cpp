#include <bits/stdc++.h>
using namespace std;
string s;
int ans=0;
int n;
int main() {
  cin >>n>> s;
  for(int i = 0;i<(int)s.size()-1;++i){
    if(s.at(i) != s.at(i+1)){
      ++ans;
    }
  }
  cout << ans+1 << endl;
  return 0;
}
