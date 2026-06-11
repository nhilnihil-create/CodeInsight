#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin >> n;
   map<string, long long> mp;
   long long ans = 0;
   for(int i = 0; i < n; i++) {
       string foo;
       cin >> foo;
       sort(foo.begin(), foo.end());
       ans += mp[foo];
       mp[foo]++;
   }
   cout << ans << endl;
}