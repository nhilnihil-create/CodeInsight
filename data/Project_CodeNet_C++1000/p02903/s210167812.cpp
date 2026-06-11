#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1LL << 30;

int main(){
  ll H, W, A, B;
  cin >> H >> W >> A >> B;
  string S1 = "";
  string S2 = "";
  for(int i = 0; i < A; i++){
    S1 += '1';
    S2 += '0';
  }
  for(int i = 0; i < W-A; i++){
    S1 += '0';
    S2 += '1';
  }
  for(int i = 0; i < H; i++){
    if(i < B) cout << S1 << endl;
    else cout << S2 << endl;
  }
}