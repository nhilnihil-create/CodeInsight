#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> bk(n,0);
  
  REP(i,n-1){
    int c;
    cin >> c;
    bk[c-1] += 1;
  }
  
  REP(i,n){
    cout << bk[i] << endl;
  }
  
  
}