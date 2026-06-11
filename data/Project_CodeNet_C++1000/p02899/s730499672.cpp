#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> pairs;
  
  REP(i,n){
    int a;
    cin >> a;
    a--;
    
    auto p = make_pair(a,i);
    pairs.push_back(p);
  }
    
  sort(pairs.begin(), pairs.end());
  
  REP(i,n){
    cout << pairs[i].second+1;
    if(i != n-1){
      cout << " ";
    }
  }
  
}