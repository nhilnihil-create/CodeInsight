#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<P> p(n);
  ll time = 0;
  rep(i,n) {
    int a, b;
    cin >> a >> b;
    p[i]=make_pair(b,a);
  }
  sort(p.begin(),p.end());
  rep(i,n) {
    time+=p[i].second;
    if(p[i].first>=time) continue;
    else {
      cout << "No" << endl; 
      return 0;
    }
  }
  cout << "Yes" << endl;
}
