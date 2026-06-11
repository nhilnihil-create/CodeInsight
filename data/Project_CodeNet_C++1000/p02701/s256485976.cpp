#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N; cin >>N;
  set<string> a;
  rep(i,0,N) {
    string b; cin >>b;
    a.insert(b);
  }
  cout <<a.size() <<endl;
  return 0;
}
