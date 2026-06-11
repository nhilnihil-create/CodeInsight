// 解説AC
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
  int n;
  cin >> n;
  map<int,int> mp;
  rep(i,n) {
    int x;
    cin >> x;
    mp[x]++;
  }
  bool ok=true;
  if(mp.size()>3) ok=false;
  else if(mp.size()==1) {
    if(!mp.count(0)) ok=false;
  }
  else if(mp.size()==2) {
    if(n%3!=0) ok=false;
    else if(mp.at(0)!=n/3) ok=false;
  }
  else {
    if(n%3!=0) ok=false;
    vector<int> a;
    for(auto p : mp) {
      if(p.second!=n/3) ok=false;
      a.push_back(p.first);
    }
    int q=a[0]^a[1]^a[2];
    if(q!=0) ok=false;
  }

  cout << (ok? "Yes" : "No") << endl;
}

