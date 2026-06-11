#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; using ll=long long; const ll LNF=1e18; const int INF = 1e9+1; const ll M = 1e9+7;
typedef pair<int,int> P;

int main() {
  string s; cin>>s;
  if (s[0] == s[1]) cout<<"Bad"<<endl;
  else if (s[1] == s[2]) cout << "Bad"<<endl;
  else if (s[2] == s[3]) cout << "Bad"<<endl;
  else cout <<"Good"<<endl;
}