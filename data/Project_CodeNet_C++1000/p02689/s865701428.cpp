#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  vector<pair<int, int>> pairs(n);
  vector<bool> yoi(n,true);
  REP(i,n){
    pairs[i].first = i;
    int c;
    cin >> c;
    pairs[i].second = c;
  }
  
  REP(i,m){
    int a,b;
    cin >> a >> b;
    
    int h1 = pairs[a-1].second;
    int h2 = pairs[b-1].second;
    if(h1 > h2){
      yoi[b-1] = false; 
    }
    else if(h2 > h1){
      yoi[a-1] = false; 
    }
    else{
      yoi[a-1] = false; 
      yoi[b-1] = false; 
    }
  }
  
  int ans = 0;
  REP(i,n){
    if(yoi[i]){
      ans++;
    }
  }
  
  cout << ans << endl;
}