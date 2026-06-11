#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  string s;
  cin>>s;
  if(s[int(s.size())-1] == 's') cout << s << "es" << endl;
  else cout << s << "s" << endl;
  return 0;
}

