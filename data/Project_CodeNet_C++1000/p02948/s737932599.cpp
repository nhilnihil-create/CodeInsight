#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n,m;
  cin >> n >> m;
  vector<pair<ll,ll>> work(n);
  for(int i = 0;i < n;i++){
    ll a,b;
    cin >> a >> b;
    work[i] = make_pair(a,b);
  }
  sort(work.begin(),work.end());
  ll res = 0;
  priority_queue<ll> que;
  ll now = 0;
  for(int i = m;i >= 0;i--){
    while(1){
      if(now > n - 1)break;
      if(work[now].first + i > m)break;
      que.push(work[now].second);
      now++;
    }
   // cout << i << " que" << que.size() << endl;
    if(!que.empty()){
      ll today = que.top();
      res += today;
      //cout << today << endl;
      //cout << i << " " << today << endl;
      que.pop();
    }
    //if(now >= n - 1)break;
  }
  cout << res << endl;
}