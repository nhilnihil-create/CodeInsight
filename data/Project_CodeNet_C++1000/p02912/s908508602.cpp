#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, m;
  cin>>n>>m;
  priority_queue<double> q;
  double d;
  rep(i, n) {
    cin>>d;
    q.push(d);
  }
  rep(i, m) {
    d = q.top();
    q.pop();
    d/=2;
    q.push(d);
  }
  ll ans = 0;
  rep(i, n){
    d = q.top();
    q.pop();
    int s = floor(d);
    ans+=s;
  }
  cout<<ans<<endl;
}