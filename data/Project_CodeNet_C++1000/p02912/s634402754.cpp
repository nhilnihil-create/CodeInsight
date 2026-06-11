#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  ll N,M; cin >> N >> M;
  priority_queue<ll> pque;
  for(int i=0;i<N;i++){
    ll x; cin >> x;
    pque.push(x);
  }
  for(int i=0;i<M;i++){
    ll y = pque.top();
    pque.pop();
    pque.push(y/2);
  }
  ll ans = 0;
  for(int i=0;i<N;i++){
    ll z = pque.top();
    pque.pop();
    ans += z;
  }
  cout << ans << endl;
}
