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
using ii = pair <ll , ll>;
void in(ll &x);
const ll N = 3050;
#define singleCase
// #define multipleCase
const ll M = 998244353;
ll n, s;
ll dp[N][N], a[N];

ll f(ll cur , ll rem) {
   if (cur > n) return rem == 0;
   ll &sol = dp[cur][rem];
   if (sol != -1) return sol;
   sol = 0;
   if (rem >= a[cur]) (sol += f(cur + 1 , rem - a[cur])) %= M;
   (sol += 2 * f(cur + 1 , rem)) %= M;
   return sol;
}

void work() {
   in(n); in(s);
   for (ll i = 1 ; i <= n ; i++) {
      in(a[i]);
   }
   memset (dp , -1 , sizeof dp);
   printf("%lld\n" , f(1 , s));
   return;
}

int main() {
   #ifdef multipleCase
      ll nQ; in(nQ);
      while (nQ--)
         work();
   #endif
   #ifdef singleCase
      work();
   #endif
   return 0;
}

void in(ll &x) {
	bool neg = false;
	register ll c;
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
