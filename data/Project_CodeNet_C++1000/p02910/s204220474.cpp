#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;

int main() {
  string s;
  cin >> s;
  bool ok=true;
  for(int i=0; i<s.size(); i++) {
    if(i%2==0&&s[i]=='L') ok=false;
    else if(i%2==1&&s[i]=='R') ok=false; 
  }
  cout << (ok? "Yes" : "No") << endl;
}