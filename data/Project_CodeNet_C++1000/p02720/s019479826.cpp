#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int k;
  cin >> k;
  ll cnt = 9;
  queue<ll> que;
  
  vector<ll> seq;
  reps(i, 1, 10) {
    seq.push_back(i);
    que.push(i);
  }
  while(!que.empty()) {
    ll cv = que.front();
    que.pop();
    ll st = max(cv % 10 - 1, (ll)0);
    ll mx = min(cv % 10 + 1, (ll)9);
    for(ll i = st; i <= mx; i++) {
      ll v = cv*10 + i;
      seq.push_back(v);
      que.push(v);
    }
    if (seq.size() - 1 >= k) {
      cout << seq.at(k-1) << endl;
      return 0;
    }   
  }
  cout << seq.size() << endl;
  return 0;
}