#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for(int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;



int main() {
  int n;
  cin >> n;
  ll k;
  cin >> k;
  vec<int> a(n+1);
  vec<int> visit(n+1, 0);
  repc(i, 1, n) cin >> a[i];  

  int len = 0;
  int now;
  int next = 1;
  repc(i, 1, n) {
    now = next;
    len++;
    visit[now] = len;
    next = a[now];
    if(len == k) {
      cout << next << endl;
      return 0;
    }
    if(visit[next] != 0) break;
  }
  
  int loop = len - visit[next] + 1;
  k -= visit[next] - 1;
  k %= loop;
  repc(i, 1, k) {
    now = next;
    next = a[now];
  }
  cout << next << endl;
  return 0;
}