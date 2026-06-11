#include "bits/stdc++.h"
using namespace std;

// #include "debug.h"
#define debug(...) 42


using ll = long long;

bool check(string s, vector <char> v) {
   int ptr = 0;
   for(int i = 0; i < s.length(); i++) {
      if(s[i] == v[ptr]) {
         ptr++;
         if(ptr == v.size()) return true;
      }
   }
   return false;
}


void solve() {
   int n;
   cin >> n;
   string s;
   cin >> s;

   int ans = 0;
   for(char i = '0'; i <= '9'; i++) {
      for(char j = '0'; j <= '9'; j++) {
         for(char k = '0'; k <= '9'; k++) {
            vector <char> v = {i, j, k};
            ans += check(s, v);
         }
      }
   }
   cout << ans << endl;
} 

int main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   int testcase = 1;
   // cin >> testcase;

   for(int i = 0; i < testcase; i++) {
      solve();
   } 
   return 0;
}
