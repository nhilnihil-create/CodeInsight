#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  REP(i,n) cin >> d[i];
  sort(d.begin(),d.end());
  int c,e;
  
  if(n % 2 == 0){
    int aa = n/2;
    c = d[aa-1];
    e = d[aa];
  }
  else cout << 0 << endl;
  
  
  if(e == c) cout << 0 << endl;
  else cout << e - c << endl;
  
}