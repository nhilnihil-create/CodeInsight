#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;

void solve(){
  ll n, ans = 0; cin >> n;
  vector<ll> v, v2;
  set<ll> st;
  for(ll i = 2; i <= sqrt(n) + 1; i++){
    if(n % i == 0){
      v.push_back(i);
      ll x = n;
      while(x % i == 0){
        x /= i;
      }
      if(x % i == 1) st.insert(i);
    }
    else if(n % i == 1){
      v2.push_back(i);
      //ans += 2;
      st.insert(i);
      st.insert((n - 1) / i);
    }
  }
  //ans += 2;
  st.insert(n - 1);
  st.insert(n);
  if(st.find(1) != st.end()) cout << st.size() - 1 << endl;
  else cout << st.size() << endl;

  /*for(int i = 0; i < v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;
  for(int i = 0; i < v2.size(); i++){
    cout << v2[i] << "," << (n - 1) / v2[i] << " ";
  }
  cout << endl;*/
  //cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
