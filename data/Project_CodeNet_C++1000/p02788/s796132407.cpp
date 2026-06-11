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
  ll n,d,a;
  cin >> n >> d >> a;
  vector<pair<ll,ll>> mon(n);
  for(int i = 0;i < n;i++){
    int pos,hp;
    cin >> pos >> hp;
    mon[i] = make_pair(pos,hp);
  }
  sort(mon.begin(),mon.end());
  vector<ll> posmemo(n);
  for(int i = 0;i < n;i++)posmemo[i] = mon[i].first;
  vector<ll> range(n);
  for(int i = 0;i < n;i++){
    range[i] = upper_bound(posmemo.begin(),posmemo.end(),posmemo[i] + 2 * d) - posmemo.begin() - 1;
  }
  //for(auto item:range)cout << item << endl;
  ll res = 0;
  vector<ll> ruiseki(n);
  vector<ll> now(n);
  for(int i = 0;i < n;i++)ruiseki[i] = 0,now[i] = 0;
  for(int i = 0;i < n;i++){
    if(i >= 1)now[i] = now[i - 1] + ruiseki[i];
    if(now[i] < mon[i].second){
      ll add = 0;
      add = (mon[i].second - now[i]) / a;
      if((mon[i].second - now[i]) % a != 0)add++;
      now[i] += add * a;
      ruiseki[i] += add * a;
      if(range[i] < n - 1)ruiseki[range[i] + 1] -= add * a;
      res += add;
    }
      /*for(auto item:ruiseki)cout << item << " ";
    cout << endl;
    for(auto item:now)cout << item << " ";
    cout << endl;*/
  }
  cout << res << endl;
  return 0;
}