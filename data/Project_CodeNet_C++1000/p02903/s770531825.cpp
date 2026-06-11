#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;

signed main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  
  for( int i = 0; i < H; i++ ){
    for( int j = 0; j < W; j++ ){
      if( j < A ){
        if( i < B ) cout << 0;
        else cout << 1;
      }else{
        if( i < B ) cout << 1;
        else cout << 0;
      }
    }
    cout << endl;
  }
}
