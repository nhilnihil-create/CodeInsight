/*
 * Author : Andrew J
*/
#include <bits/stdc++.h>
using namespace std;
#define rall(x) x.rbegin() , x.rend()
#define all(x) x.begin() , x.end()
#define fi first
#define se second
#define pb push_back
using ll = long long;
using ii = pair <int , int>;
void in(int &x);
const int N = 1e5 + 10;
#define singleCase
// #define multipleCase
int n,a[N];
map <int , int> freq;

void work() {
   in(n);
   for (int i = 1 ; i <= n ; i++) {
      in(a[i]);
      freq[a[i]]++;
   }
   if (freq.size() > 3) {
      puts("No");
      return;
   } else if (freq.size() == 3) {
      int res = 0, lowest = INT_MAX;
      for (ii x : freq) {
         res ^= x.fi;
         lowest = min(lowest , x.se);
      }
      if (res != 0) {
         puts("No");
         return;
      }
      for (ii x : freq) {
         if (x.se - lowest > 0) {
            puts("No");
            return;
         }
      }
   } else if (freq.size() == 2) {
      vector <int> v;
      for (ii x : freq) {
         v.pb(x.fi);
      }
      if (v[0] == 0) {
         if (freq[0] * 2 != freq[v[1]]) {
            puts("No");
            return;
         }
      } else if (v[1] == 0) {
         if (freq[0] * 2 != freq[v[0]]) {
            puts("No");
            return;
         }
      } else {
         puts("No");
         return;
      }
   } else {
      for (ii x : freq) {
         if (x.fi != 0) {
            puts("No");
            return;
         }
      }
   }
   puts("Yes");
   return;
}

int main() {
   #ifdef multipleCase
      int nQ; in(nQ);
      while (nQ--)
         work();
   #endif
   #ifdef singleCase
      work();
   #endif
   return 0;
}

void in(int &x) {
	bool neg = false;
	register int c;
	x = 0;
	c = getchar();
	if(c == '-') {
		neg = true;
		c = getchar();
	}
	for (; c > 47 && c < 58; c = getchar())
	  x = (x << 1) + (x << 3) + c - 48;
	if (neg) x *= -1;
}
