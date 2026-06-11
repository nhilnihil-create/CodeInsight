#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 2e9;
int N, K;
int A[200005], B[200005];

int main() {
  INCANT;
  cin >> N >> K;
  rep(i, N) cin >> A[i];
  int cnt=0;
  while(cnt<K) {
    fill(B, B+N, 0);
    rep(i, N) {
      B[max(i-A[i], 0)]++;
      B[min(i+A[i]+1, N)]--;
    }
    A[0]=B[0];
    bool flag=A[0]==N;
    for (int i=1;i<N;i++) {
      A[i] = A[i-1]+B[i];
      if (A[i]<N) flag=false;
    }
    if (flag) break;
    cnt++;
  } 
  rep(i, N) cout << A[i] << ' ';
  cout << endl;
  return 0;
}