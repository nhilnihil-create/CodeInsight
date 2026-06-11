#include <bits/stdc++.h>
using namespace std;

int main() {
   string S;
   cin >> S;
   int count=0;
   int n = S.size()/2;
   string a = S.substr(0, n);
   reverse(S.begin(), S.end());
   string b = S.substr(0, n);

   for(int i=0; i<n; i++) {
      if(a[i] != b[i]) count++;
   }
   cout << count << endl;
}