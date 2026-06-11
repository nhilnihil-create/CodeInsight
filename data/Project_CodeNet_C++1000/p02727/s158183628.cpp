#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<int> p(a);
  vector<int> q(b);
  vector<int> r(c);
  rep(i, a){
    cin >> p[i];
  }
  rep(i, b){
    cin >> q[i];
  }
  rep(i, c){
    cin >> r[i];
  }
  sort(p.begin(), p.end(), greater<int>());
  sort(q.begin(), q.end(), greater<int>());
  sort(r.begin(), r.end(), greater<int>());
  priority_queue<int, vector<int>, greater<int> > red;
  priority_queue<int, vector<int>, greater<int> > green;
  rep(i, x){
    red.push(p[i]);
  }
  rep(i, y){
    green.push(q[i]);
  }
  rep(i, c){
    if(red.top()>=r[i] && green.top()>=r[i])break;
    if(red.top()>=green.top()){
      green.pop();
      green.push(r[i]);
    } else {
      red.pop();
      red.push(r[i]);
    }
  }
  ll ans=0;
  while(!red.empty()){
    ans+=red.top();
    red.pop();
  }
  while(!green.empty()){
    ans+=green.top();
    green.pop();
  }
  cout << ans << endl;
  return 0;
}
