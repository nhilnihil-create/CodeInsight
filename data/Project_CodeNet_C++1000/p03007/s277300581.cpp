#include<bits/stdc++.h>
#define endl '\n';
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
constexpr ll INF = 1e18;
constexpr int inf = 1e9;
constexpr double INFD = 1e100;
constexpr ll mod = 1000000007;
constexpr ll mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
// ---------------------------------------------------------------------------

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  ll sum = 0;
  rep(i,N){
    cin >> A[i];
    sum += abs(A[i]);
  }
  sort(A.begin(),A.end());
  if(A[N-1] <= 0){
    cout << sum+A[N-1]*2 << endl;
    ll now = A[N-1];
    rep(i,N-1){
      cout << now << " " << A[i] << endl;
      now -= A[i];
    }
  }else if(A[0] >= 0){
    cout << sum-A[0]*2 << endl;
    ll now = A[0];
    for(int i=1; i<N-1; i++){
      cout << now << " " << A[i] << endl;
      now -= A[i];
    }
    cout << A[N-1] << " " << now << endl;
  }else{
    cout << sum << endl;
    int pos = lower_bound(A.begin(),A.end(),0) - A.begin();
    for(int i=pos; i<N-1; i++){
      cout << A[0] << " " << A[i] << endl;
      A[0] -= A[i];
    }
    for(int i=0; i<pos; i++){
      cout << A[N-1] << " " << A[i] << endl;
      A[N-1] -= A[i];
    }
  }
  return 0;
}
