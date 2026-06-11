#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define ff first
#define ss second
#define pb push_back
#define sz size()
#define mp make_pair

const int N = 2005;
const int MOD = 1e9 + 7;

pair<int, int> A[N];
ll dp[N][N];
int n;

ll call(int i, int L){

  if(i == n) return 0;
  if(dp[i][L] != -1)return dp[i][L];
  int R = n - 1 - (i - L);
  // cout << L << ' ' << R << endl;
  ll ret = 1LL * A[i].ff * abs(L - A[i].ss) + call(i + 1, L + 1);
  if(L != R)ret = max(ret, 1LL * A[i].ff * abs(R - A[i].ss) + call(i + 1, L));
  return dp[i][L] = ret;
}

int main() {

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> A[i].ff;
    A[i].ss = i;
  }
  sort(A, A + n, greater<pii>());
  memset(dp, -1, sizeof dp);
  cout << call(0, 0) << endl;
  return 0;
}