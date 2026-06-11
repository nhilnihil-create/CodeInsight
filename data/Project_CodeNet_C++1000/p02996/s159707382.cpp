#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define rep1(i,n) for(int i=1; i<(int)n; i++)
#define repa(i,a,n) for(int i=(a); i<(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
#define COUT(x) cout<<(x)<<endl
#define YES(x) cout<<(x?"YES":"NO")<<endl
#define Yes(x) cout<<(x?"Yes":"No")<<endl
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
string S, T;

signed main(){
  cin >> N;
  vvi work(N,vi(2));
  int crt = 0;
  rep(i,N){
    cin >> work[i][1] >> work[i][0];
    crt += work[i][1];
  }
  sort(all(work));
  reverse(all(work));  
  
  if(crt > work[0][0]) {Yes(0); return 0;}
  else crt = work[0][0];
  rep(i,N){
    if(crt<=work[i][0]) crt -= work[i][1];
    else crt = work[i][0]-work[i][1];
  }
  Yes(crt>=0);
  return 0;
}
