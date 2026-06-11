#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<vector<int>> range(n,(vector<int>(2)));
  rep(i, n){
    int x, r;
    cin >> x >> r;
    range.at(i).at(0) = x+r;
    range.at(i).at(1) = x-r;  
  };
  sort(range.begin(),range.end());
  int c = 1;
  int a = range.at(0).at(0);
  rep(i,n-1){
    if(range.at(i+1).at(1) >= a){
      c++;
      a = range.at(i+1).at(0);
    }
    else if(range.at(i+1).at(1) < a){
      continue;
    }
  };
  cout << c << endl;
}