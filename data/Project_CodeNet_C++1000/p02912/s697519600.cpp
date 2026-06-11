#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n, m;
  cin >> n >> m;
  priority_queue<int> a;
  rep(i,n){
    int b;
    cin >> b;
    a.push(b);
  }
  rep(i,m){
    int tp = a.top();
    tp /= 2;
    a.pop();
    a.push(tp);
  }
  ll ans=0;
  rep(i,n) {
    ans += a.top();
    a.pop();
  }
  cout << ans << endl;
}
