#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  string s;
  cin >> s;
  set<char> a;
  for(int i=0;i<4;i++){
    a.insert(s.at(i));
  }
  if(a.size()==2)
  cout << "Yes" << endl;
  else
  cout << "No" << endl;
}

