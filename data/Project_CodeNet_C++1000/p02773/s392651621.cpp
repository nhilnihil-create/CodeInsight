#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  map<string,int> s;
  vector<string> b(n);
  rep(i,n){
   string a;
    cin >> a;
    b[i] = a;
    s[a]++;
  }
  //cout << b[1] << endl;
  //cout << s << endl;
  int maxim =0;
  for (auto p : s) {
  auto k = p.first;
  auto v = p.second;
    if(maxim < v) maxim = v;
  //cout << k << " => " << v << endl;
}
  for (auto p : s) {
  auto k = p.first;
  auto v = p.second;
    if(v == maxim) cout << k << endl;
}
}
