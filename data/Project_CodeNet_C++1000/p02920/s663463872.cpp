#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
  fastIO;
  int n;
  cin >> n;
  int k = (1 << n);
  multiset<int> cur;
  multiset<int> val;
  int x;
  for(int i = 0 ; i < k ; i ++ ){
    cin >> x;
    x=-x;
    val.insert(x);
  }
  cur.insert(*(val.begin()));
  val.erase(val.begin());
  while(!val.empty()){
    vector<int> sol;
    for(auto x : cur){
      auto it = val.upper_bound(x);
      if(it == val.end()){
        cout << "No\n";
        return 0;
      }
      sol.push_back(*it);
      val.erase(it);
    }
    for(auto y : sol) cur.insert(y);
  }
  cout << "Yes\n";
  return 0;
}