#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <bitset>

#define rep(i, a, b) for ( ll i = (a); i < (b); i++ )
#define per(i, a, b) for ( ll i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<int, int>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

const int MAX_ROW = 100005;
const int MAX_COL = 100;

struct BitMatrix {
  int H, W;
  bitset<MAX_COL> val[MAX_ROW];
  BitMatrix(int h = 1, int w = 1) : H(h), W(w) {}
  inline bitset<MAX_COL>& operator [] (int i) { return val[i]; }
};

int xor_elimination(BitMatrix &A) {
  //rep(i, 0, A.H) cout << A[i] << endl;
  //cout << "\n";
  int COL = A.W, ROW = A.H;
  int rank = 0;
  for (int col = COL-1; col>=0; col--) {
    int pivot = -1;
    for (int row = rank; row<ROW; row++) {
      if (A[row][col]) {
        pivot = row;
        break;
      }
    }
    
    if (pivot == -1) continue;
    swap(A[pivot], A[rank]);
    
    for (int row = 0; row<ROW; row++) {
      if (row != rank && A[row][col]) A[row] ^= A[rank];
    }
    
    rank++;
  }
  return rank;
}
/*
bool is_make_xor(BitMatrix &A, int rank, long long num) {
  for (int i=0; i<rank; i++) {
    int p = -1;
    for (int j=A.
  
  }
  

}
*/

int n;
ll a[100005], ans;

int main(void) {
  cin >> n;
  
  BitMatrix M(n, MAX_COL);
  rep (i, 0, n) {
    cin >> a[i];
    M[i] = a[i];
  }
  
  for (int d=61; d>=0; d--) {
    int num = 0;
    for (int i=0; i<n; i++) num += M[i][d];
    
    if (num%2) {
      ans += (1LL<<d);
      for (int i=0; i<n; i++) M[i][d] = 0;
    }
  }
 
  int rank = xor_elimination(M);
  
  bitset<MAX_COL> b;
  rep(i, 0, rank) b ^= M[i];
  
  rep(i, 0, 62) ans += (1LL<<(i+1))*b[i];
  
  cout << ans << endl;
   
    return 0;
}
