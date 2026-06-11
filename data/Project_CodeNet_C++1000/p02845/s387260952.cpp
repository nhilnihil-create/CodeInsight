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

#define MOD 1000000007

int main(){
  int N;
  cin >> N;
  ll ans = 1;
  vi R = {-1}, B = {-1}, G = {-1};
  for(int i = 0; i < N; i++){
    int A;
    cin >> A;
    int counter = 0;
    if(*(R.end()-1) == A - 1) counter++;
    if(*(B.end()-1) == A - 1) counter++;
    if(*(G.end()-1) == A - 1) counter++;

    if(*(R.end()-1) == A - 1) R.push_back(A);
    else if(*(B.end()-1) == A - 1) B.push_back(A);
    else if(*(G.end()-1) == A - 1) G.push_back(A);
    ans *= counter;
    ans %= MOD;
  }
  cout << ans << endl;

}