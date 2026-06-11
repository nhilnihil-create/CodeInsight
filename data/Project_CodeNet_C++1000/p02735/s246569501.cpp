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
const int N = 105;
#define singleCase
// #define multipleCase
const int inf = 1e8;
int n,m,dp[N][N];
char grid[N][N];

int dr[] = {0 , 1};
int dc[] = {1 , 0};

bool inside(int r , int c) {
   return r >= 1 && r <= n && c >= 1 && c <= m;
}

int f(int r , int c) {
   if (r == n && c == m) return grid[r][c] == '#';
   int &sol = dp[r][c];
   if (sol != -1) return sol;
   sol = inf;
   for (int i = 0 ; i < 2 ; i++) {
      if (!inside(r + dr[i] , c + dc[i])) continue;
      int nr = r + dr[i], nc = c + dc[i];
      sol = min(sol , f(nr , nc) + (grid[nr][nc] == '.' && grid[r][c] == '#'));
   }
   return sol;
}

void work() {
   memset (dp , -1 , sizeof dp);
   cin >> n >> m;
   for (int i = 1 ; i <= n ; i++) {
      for (int j = 1 ; j <= m ; j++) {
         cin >> grid[i][j];
      }
   }
   printf("%d\n" , f(1 , 1));
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
