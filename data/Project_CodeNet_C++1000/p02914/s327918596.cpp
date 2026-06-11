#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

// Bit Matrix
const int MAX_ROW = 100010; // to be set appropriately
const int MAX_COL = 63; // to be set appropriately
struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL>& operator [] (int i) {return val[i];}
};

int GaussJordan(BitMatrix &A, bool is_extended = false) {
    int rank = 0;
    for (int col = 0; col < A.W; ++col) {
        if (is_extended && col == A.W - 1) break;
        int pivot = -1;
        for (int row = rank; row < A.H; ++row) {
            if (A[row][col]) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(A[pivot], A[rank]);
        for (int row = 0; row < A.H; ++row) {
            if (row != rank && A[row][col]) A[row] ^= A[rank];
        }
        ++rank;
    }
    return rank;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int MD = 63;
  BitMatrix B(n,MD);
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  set<int> use;
  ll ans = 0;
  rep(i,MD){
    ll v = 0;
    rep(j,n){
      v = v ^ ((a[j] & (1LL<<i)) > 0);
    }
    if(v==1) {
      ans += 1LL<<i;
      use.insert(i);
      // cout << i << endl;
    }
  }
  rep(i,MD){
    if(use.count(i)) continue;
    rep(j,n){
      if(a[j]&(1LL<<i)){
      // cout << i  << " " << j << endl;
        B[j][MD-1-i] = 1;
      }
      else B[j][MD-1-i] = 0;
    }
  }
  GaussJordan(B,false);
  rep(i,MD){   
    int cnt = 0;
    rep(j,n){
      if(B[j][MD-1-i]) cnt++;
    }
    if(cnt&1) {
      ans += 1LL<<(i+1);
      // cout << ans << endl;
    }
  }
  cout << ans << endl;
  return 0;
    

}
