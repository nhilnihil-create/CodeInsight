#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define rep1(i,n) for(int i=1; i<(int)n; i++)
#define repa(i,a,n) for(int i=(a); i<(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using psi = pair<string, int>;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};
const int mod = 1e9+7;
int gcd(int a, int b){if(a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a / gcd(a, b)*b;}

int N, M, K, H, W, L, R, X;
//string S, T;

signed main(){
  cin >> N;
  vi w(N);
  int rsum = 0;
  rep(i,N){
    cin >> w[i];
    rsum += w[i];
  }
  int lsum=0;
  int ans = 1e9;
  rep(i,N-1){
    lsum += w[i];
    rsum -= w[i];
    ans = min(ans, abs(lsum-rsum));
  }
  cout << ans << endl;
  return 0;
}
