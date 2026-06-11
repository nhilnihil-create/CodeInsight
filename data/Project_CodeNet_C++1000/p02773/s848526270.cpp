#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
#define _GLIBCXX_DEBUG

int main() {
  int n; cin >> n;
  vector<string> vec(n);
  rep(i,n) cin >> vec[i];

  map<string,int> num;
  rep(i,n) num[vec[i]]++;

  //rep(i,n) cout << num[vec[i]] << endl;

  int max = 0;;
  for(auto p : num){
    auto k = p.first;
    auto v = p.second;
    if(max < v) max = v;
  }

  //cout << max << endl;

  for(auto p : num){
    auto k = p.first;
    auto v = p.second;
    if(v == max) cout << k << endl;
  }

  return 0;
}
