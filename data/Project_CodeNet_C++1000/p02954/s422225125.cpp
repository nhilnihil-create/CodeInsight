#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
/* start */

signed main(){
   IOS;
   string s; cin >> s;
   int n = s.size();
   vector<int> ans(n), l(n), r(n);
   for(int i = 0, cur = 0; i < n; i++) {
      if(s[i] == 'R') cur = 0;
      else cur++;
      r[i] = cur;
   }
   for(int i = n - 1, cur  = 0; i >= 0; i--) {
      if(s[i] == 'L') cur = 0;
      else cur++;
      l[i] = cur;
   }
   for(int i = 0; i < n - 1; i++) {
      if(l[i] == 0) continue;
      if(l[i]%2 == 0) {
         ans[i + l[i]]++;
      }
      else ans[i + l[i] - 1]++;
   }
   for(int i = n - 1; i > 0; i--) {
      if(r[i] == 0) continue;
      if(r[i]%2 == 0) {
         ans[i - r[i]]++;
      }
      else ans[i - r[i] + 1]++;
   }
   for(auto x : ans) cout << x << " ";
}