#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, now=0;
  cin>>n;
  vector<pii> p(n);
  int a, b;
  rep(i, n){
    cin>>a>>b;
    p.at(i) = make_pair(b, a);
  }
  sort(p.begin(), p.end());
  
  bool ans = true;
  rep(i, n){
    now+=p.at(i).second;
    if(p.at(i).first<now){
      ans = false;
      break;
    }
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}