#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  int n; cin >>n;
  vector<pair<int, int>> p(n);
  rep(i,n) {
    int a,b; cin >>a >>b;
    p.emplace_back(b,a);
  }
  sort(p.begin(), p.end());
  int sum = 0;
  bool can = true;
  for(auto v : p){
    sum += v.second;
    if(sum>v.first){
      can = false;
      break;
    }
  }
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}