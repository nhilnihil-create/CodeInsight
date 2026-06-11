#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  int n;
  cin >> n;
  map<string,int> m;
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    if(m.count(s))
    m[s]++;
    else
    m[s]=1;
  }
  int max=0;
  for (auto p : m) {
    auto v = p.second;
    if(max<v)
    max=v;
  }
  for (auto p : m) {
    auto k = p.first;
    auto v = p.second;
    if(v==max)
    cout << k << endl;
  }
}