#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n; cin >> n;
   map<map<char, ll>,ll> m;
   while(n--){
      string s; cin >> s;
      map<char,ll> mp;
      for (auto &&j : s){
         mp[j]++;
      }
      m[mp]++;
   }
   ll ans = 0;
   for (auto &&i : m){
      ans += (i.second*(i.second-1))/2;
   }
   cout << ans << endl;
   
}