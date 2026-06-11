#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'

template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

typedef long long ll;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int n, m;  cin >> n >> m;
  vector<int> h(n); cin >> h;
  vector<int> good(n, 1);
  while (m--){
    int u, v; cin >> u >> v;  u--, v--;
    if(h[u]>=h[v]) good[v] = 0;
    if(h[v]>=h[u]) good[u] = 0;
  }
  cout << count(good.begin(), good.end(), 1) << "\n";
  return 0;
}