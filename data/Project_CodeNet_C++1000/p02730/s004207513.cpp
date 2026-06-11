#include <bits/stdc++.h>
using namespace std;

int main() {
   string s;
   cin >> s;
   int n = s.size();

   for(int i=0; i<n; i++) {
      if(s[i] != s[n-1-i]) {
         cout << "No" << endl;
         return 0;
      }
   }
   int m = (n-1) / 2;
   int l = (n+3) / 2;

   for(int i=0; i<m; i++) {
      if(s[i] != s[m-1-i]) {
         cout << "No" << endl;
         return 0;
      }
   }

   for(int i=l; i<n-l+1; i++) {
      if(s[l] != s[n-l-i+1]){
         cout << "No" << endl;
         return 0;
      }
   }
   cout << "Yes" << endl;
}