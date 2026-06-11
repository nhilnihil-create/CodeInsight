#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main() {
  int n;
  cin >> n;
  if(n == 1){
    cout << 1 << endl;
    return 0;
  }
  vector<pair<ll, ll>> vec;
  rep(i, n){
    ll a, b;
    cin >> a >> b;
    vec.push_back(make_pair(a, b));
  }
  ll smallest = 100;
  rep(i, n-1){
    for(ll j=i+1; j<n; j++){
      ll p = vec[j].first - vec[i].first;
      ll q = vec[j].second - vec[i].second;
      ll cost = 0;
      vector<ll> flag(n, 0);
      while(find(all(flag), 0) != flag.end()){
        ll index = find(all(flag), 0) - flag.begin();
        queue<vector<ll>> que;
        vector<ll> tmp = {vec[index].first, vec[index].second, index};
        que.push(tmp);
        while(!que.empty()){
          vector<ll> tmpv = que.front();
          que.pop();
          ll x = tmpv[0], y = tmpv[1], ind = tmpv[2];
          flag[ind] = 1;
          for(ll k=0; k<n; k++){
            if(flag[k] == 0){
              if((vec[k].first - x == p && vec[k].second - y == q) || (vec[k].first - x == -p && vec[k].second - y == -q)){
                vector<ll> t = {vec[k].first, vec[k].second, k};
                que.push(t);
              }
            }
          }
        }
        cost++;
      }
      smallest = min(smallest, cost);
    }
  }
  cout << smallest << endl;
  return 0;
}
  
  
  
  