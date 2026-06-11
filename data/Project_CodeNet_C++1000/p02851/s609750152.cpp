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
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n + 1);
  a[0] = 0;
  for(int i = 1;i < n+1;i++){
    ll num = 0;
    cin >> num;
    a[i] = a[i - 1] + num;
  }
  /*for(auto& item:a)cout << item << " ";
  cout << endl;*/
  if(k == 1){
    cout << 0 << endl;
    return 0;
  }
  map<ll,ll> count;
  count[0]++;
  ll res = 0;
  if(a[1] % k == (ll)1)res++;
  for(int i = 1;i < n;i++){
    count[(a[i] - (i)) % k]++;
    if(i >= k - 1)count[(a[i - (k - 1)] - (i - (k - 1))) % k]--;//,cout << i << endl;
    res += count[(a[i + 1] - (i + 1)) % k];
    //cout << "i" << i << " " << res << endl;
        //for(auto& item:count)cout << i << "i " << item.first << " " << item.second << endl;
  }
  cout << res << endl;
  return 0;
}