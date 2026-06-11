#include<vector>
#include<iostream>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
ll n,k;
bool flag = false;
vector<vector<int>> v(100005);
vector<bool> c(100005);
ll ans = 1;

int func(int node, ll x){
  c[node] = true;
  if(flag) return 0;
  if(k-x <= 0){flag = true; return 0;}
  ans = (ans * (k-x)) % MOD;
  ll deg = 0;
  ll cnt = 0;
  vector<int> tonode;
  for(auto vt: v[node]){
    if(!c[vt]) tonode.push_back(vt);
    if(c[vt]) cnt++;
  }
  if(cnt == 0) cnt = 1;
  else cnt = 2;
  for(auto vt: tonode){
  	func(vt, deg+cnt); deg++;
  }
  return 0;
}


int main(){
   cin >> n >> k;
  for(int i=0;i<n-1;i++){
  	int f,t; cin >> f >> t;
  	v[f-1].push_back(t-1);
    v[t-1].push_back(f-1);
  }
  func(0,0);
  if(flag) cout << 0 << endl;
  else cout << ans << endl;
  return 0;
}