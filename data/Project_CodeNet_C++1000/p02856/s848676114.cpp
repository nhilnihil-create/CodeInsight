#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
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
  ll M;
  cin >> M;
  ll ketasum = 0;
  ll keta = 0;
  for(int i = 0; i < M; i++){
    ll d, c;
    cin >> d>> c;
    ketasum += d * c;
    keta += c;
  }
  cout << ((ketasum + 8)/ 9 - 1 + keta - 1) << endl;
}