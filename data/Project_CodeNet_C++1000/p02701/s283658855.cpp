#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int main(){
  int n;
  string a;
  cin >> n;
  set<string> s;
  rep(i,n){
    cin >> a;
    s.insert(a);
  }
  cout << s.size() << endl;
  return 0;
}