#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < n; ++i)


main() {
  string s;cin>>s;
  bool p=s[0]=='R';
  bool q=s[1]=='R';
  bool r=s[2]=='R';
  if(p&&q&&r){
    cout << 3 << endl;
  } else if((p&&q)||(q&&r)){
    cout << 2 << endl;
  } else if(p||q||r){
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
}