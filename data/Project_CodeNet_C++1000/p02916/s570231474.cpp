#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
  int n;
  int cost = 0;
  cin >> n;
  std::vector<int> a(n);
  std::vector<int> b(n);
  std::vector<int> c(n-1);
  rep(i, n) cin >> a.at(i);
  rep(i, n){
    cin >> b.at(i);
    cost += b.at(i);
  }
  rep(i, n-1) cin >> c.at(i);
  
  rep(i, n-1){
    if(a.at(i+1) - a.at(i) == 1){
      cost += c.at(a.at(i) - 1);
    }
  }

  std::cout << cost << '\n';
  
  return 0;
}