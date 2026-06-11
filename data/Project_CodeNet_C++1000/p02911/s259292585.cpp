#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,k,q,sum = 0;
  cin >> n >> k >> q;
  sum = n*k;
  vector<int> a(n,k);
  vector<int> mp(n,q);
  REP(i,q){
    int aa;
    cin >> aa;
    aa--;
    mp[aa]--;
  }
  
  REP(i,n){
    a[i] -= mp[i];
  }
  
  REP(i,n){
    if(a[i] > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
