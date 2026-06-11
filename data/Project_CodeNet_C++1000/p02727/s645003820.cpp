#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  int X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
  int p[A], q[B], r[C];
  rep(i,A) cin >> p[i];
  rep(i,B) cin >> q[i];
  rep(i,C) cin >> r[i];
  sort(p,p+A,greater<int>());
  sort(q,q+B,greater<int>());
  sort(r,r+C,greater<int>());

  priority_queue<int,vector<int>,greater<int>> l;
  rep(i,X) l.push(p[i]);
  rep(i,Y) l.push(q[i]);

  int idx = 0;
  while (idx<C) {
    int MIN = l.top();
    if (MIN>=r[idx]) break;
    
    l.pop();
    l.push(r[idx]);
    idx++;
  }

  ll ans = 0;
  while (!l.empty()){
    ans += l.top(); l.pop();
  }
  cout << ans << endl;

    

  // cout << fixed << setprecision(10);
  
  return 0;
}
