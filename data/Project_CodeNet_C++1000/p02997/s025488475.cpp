#include <bits/stdc++.h>
#define reg register
#define ll long long
#define ull unsigned long long
#define db double
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vector<pl>
#define pb push_back
#define er erase
#define SZ(x) (int) x.size()
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mkp make_pair
#define dmin(x, y) ((x) < (y) ? (x) : (y))
#define dmax(x, y) ((x) > (y) ? (x) : (y))
#define checkmax(x, y) ((x) < (y) ? ((x) = (y)) : (x))
#define checkmin(x, y) ((x) > (y) ? ((x) = (y)) : (x))
#define ms(data_name) memset(data_name, 0, sizeof(data_name))
#define msn(data_name, num) memset(data_name, num, sizeof(data_name))
#define For(i, j) for(reg int (i) = 1; (i) <= (j); ++(i))
#define For0(i, j) for(reg int (i) = 0; (i) < (j); ++(i))
#define Forx(i, j, k) for(reg int (i) = (j); (i) <= (k); ++(i))
#define Forstep(i , j, k, st) for(reg int (i) = (j); (i) <= (k); (i) += (st))
#define fOR(i, j) for(reg int (i) = (j); (i) >= 1; (i)--)
#define fOR0(i, j) for(reg int (i) = (j) - 1; (i) >= 0; (i)--)
#define fORx(i, j, k) for(reg int (i) = (k); (i) >= (j); (i)--)
#define tour(i, u) for(reg int (i) = head[(u)]; (i) != -1; (i) = nxt[(i)])
using namespace std;
char ch, B[1 << 20], *S = B, *T = B;
#define getc() (S == T && (T = (S = B) + fread(B, 1, 1 << 20, stdin), S == T) ? 0 : *S++)
#define isd(c) (c >= '0' && c <= '9')
int rdint() {
  int aa, bb;
  while(ch = getc(), !isd(ch) && ch != '-');
  ch == '-' ? aa = bb = 0 : (aa = ch - '0', bb = 1);
  while(ch = getc(), isd(ch))
    aa = aa * 10 + ch - '0';
  return bb ? aa : -aa;
}
ll rdll() {
  ll aa, bb;
  while(ch = getc(), !isd(ch) && ch != '-');
  ch == '-' ? aa = bb = 0 : (aa = ch - '0', bb = 1);
  while(ch = getc(), isd(ch))
    aa = aa * 10 + ch - '0';
  return bb ? aa : -aa;
}
const int MAXN = 110;
int n, k;
inline void work() {
  n = rdint();
  k = rdint();
  int m = n * (n - 1) / 2 - k;
  if(m < n - 1) {
    m = -1;
  }
  printf("%d\n", m);
  if(m != -1) {
    int tmp = n - 1;
    while(m > 0) {
      Forx(i, n - tmp + 1, min(n, n - tmp + m)) {
        printf("%d %d\n", n - tmp, i);
      }
      m -= tmp--;
    }
  }
}
int main() {
  // freopen("input.txt", "r", stdin);
  work();
  return 0;
}
