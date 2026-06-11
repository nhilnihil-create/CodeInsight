#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define PI 3.14159265359
using namespace std;
using ll = long long;

bool kaibun(string s){
  string t(s.rbegin(), s.rend());
  return s == t;
}

int main(){
  string s;
  cin >> s;
  int n = s.size();
  cout << (kaibun(s) && kaibun(s.substr(0,(n-1)/2)) && kaibun(s.substr((n+1)/2))?"Yes":"No") << endl;
  return 0;
}
