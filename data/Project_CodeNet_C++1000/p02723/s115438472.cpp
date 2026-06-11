#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int ll
#define endl "\n"
#define all( x ) x.begin(), x.end()
#define fast ios::sync_with_stdio(0);cin.tie(0);

typedef unsigned long long ull;

const int inf = 1e9 + 5;
const long double PI = 3.141592653589793;

void solve(){
  string s;
  cin >> s;
  cout << ((s[2] == s[3] && s[4]==s[5]) ? "Yes":"No") << endl;
  return;
}  
signed main(){
  fast;
  int t;
  t = 1;
  //cin>>t;
  while(t--){
    solve();
  }
}