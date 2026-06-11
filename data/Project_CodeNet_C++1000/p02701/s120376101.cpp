#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int n;
  cin >> n;
  set<string> s;
  rep(i,n){
    string a;
    cin >> a;
    s.insert(a);
  }
  cout << s.size() << endl;
  return 0;
}