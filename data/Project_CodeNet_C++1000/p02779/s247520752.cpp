#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N; cin >>N;
  set<int> A;
  rep(i,0,N) {
    int temp; cin >>temp;
    A.insert(temp);
  }
  cout <<((int)A.size()==N ? "YES":"NO") <<endl;
  return 0;
}
