#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
   string s;
   cin >> s;
   string b = s;
   reverse(b.begin(),b.end());
   int cnt = 0;
   if (s == b) {
	   cnt++;
   }
   int n = (int)s.size();
   string s1 = "";
   string s2 = "";
   for (int i = 0; i < (n - 1) / 2; ++i) {
	   s1 += s[i];
   } 
   for (int i = ((n + 3) / 2) - 1; i < n; ++i) {
	   s2 += s[i];
   }
 //  cout << s1 << " " << s2;
   string s3 = s1;
   string s4 = s2;
   reverse(s3.begin(),s3.end());
   reverse(s4.begin(),s4.end());
   if (s1 == s3) cnt++;
   if (s2 == s4) cnt++;
   if (cnt == 3) {
	   cout << "Yes";
   }else {
	   cout << "No";
   }
}

















