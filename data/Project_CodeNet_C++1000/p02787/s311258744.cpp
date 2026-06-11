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
const int N = 1005;
const int inf = 1e9;
#define singleCase
// #define multipleCase
int h,n,a[N],b[N],dp[N][10005];

int f(int cur , int health) {
   if (health <= 0) return 0;
   if (cur > n) return inf;
   int &sol = dp[cur][health];
   if (sol != -1) return sol;
   return sol = min(f(cur + 1 , health) , f(cur , health - a[cur]) + b[cur]);
}

void work() {
   in(h); in(n);
   for (int i = 1 ; i <= n ; i++) {
      in(a[i]); in(b[i]);
   }
   memset (dp , -1 , sizeof dp);
   printf("%d\n" , f(1 , h));
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
