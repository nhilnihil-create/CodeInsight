#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  vector<pair<bool, int>> pairs(n,pair<bool, int>(false,0));
  
  REP(i,m){
    int p;
    string s;
    cin >> p >> s;
    p--;
    
    if(pairs[p].first == false){
      if(s == "AC"){
        pairs[p].first = true;
      }
      else{
        pairs[p].second += 1;
      }
    }
    
  }
    
  int ans1 = 0,ans2 = 0;
    
  REP(i,n){
    if(pairs[i].first){
      ans1++;
      ans2 += pairs[i].second;
    }
  }
      
  
  cout << ans1 << " " << ans2 << endl;
}