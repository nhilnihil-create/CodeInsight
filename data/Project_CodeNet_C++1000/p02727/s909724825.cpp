//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll P[MAX], Q[MAX], R[MAX];
int x, y, a, b, c;

bool cmp(ll i, ll j) {
   return i > j;
}

int main() {
   cin >> x >> y >> a >> b >> c;

   for (int i = 0; i < a; i++)
      cin >> P[i];
   
   sort(P, P + a, cmp);
   
   for (int i = 0; i < b; i++)
      cin >> Q[i];
   
   sort(Q, Q + b, cmp);
         
   for (int i = 0; i < c; i++)
      cin >> R[i];

   sort(R, R + c, cmp);
   
   ll ans = 0;

   for (int i = 0; i < x; i++) ans += P[i];
   for (int i = 0; i < y; i++) ans += Q[i];

   for (int i = 0; i < c; i++) {
      int red = -1;
      if (x == 0 && y == 0) break;
      else if (x == 0) red = 1;
      else if (y == 0) red = 0;
      else if (P[x - 1] < Q[y - 1]) red = 0;
      else red = 1;

      if (red == 1 && Q[y - 1] < R[i]) {
         ans += (R[i] - Q[y - 1]);
         y--;
      } else if (red == 0 && P[x - 1] < R[i]) {
         ans += (R[i] - P[x - 1]);
         x--;
      } else break;      
   }

   cout << ans << '\n';
}
