#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 9e18;
constexpr int inf = 1e9;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};

// intやllをstringに変換
template<typename T> inline string toString(const T &a){
  ostringstream oss;
  oss << a;
  return oss.str();
};
// ----------------------------------------------------------------------------

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  ll ans = 1;
  vector<int> num(3,-1);
  for(int i=0; i<N; i++){
    ll cnt = 0;
    for(int j=0; j<3; j++){
      if(A[i]-1 == num[j]){
        cnt++;
      }
    }
    for(int j=0; j<3; j++){
      if(A[i]-1 == num[j]){
        num[j]++;
        break;
      }
    }
    ans *= cnt;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
