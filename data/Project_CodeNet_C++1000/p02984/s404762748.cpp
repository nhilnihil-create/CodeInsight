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
//cout << fixed << setprecision(15);
int N, M, K, H, W, L, R, X, Y;
//string S, T;

signed main(){
  cin >> N;
  vi D(N);
  int sum = 0;
  int Asum =0;
  rep(i,N){
    cin >> D[i];
    sum += D[i];
    if(i%2 == 1) Asum += D[i];
  }
  vi Y(N);
  Y[0] = sum-2*Asum;
  rep1(i,N) Y[i]=2*D[i-1]-Y[i-1];
  
  rep(i,N){
    cout << Y[i];
    if(i != N-1) cout << " ";
  }
  cout << endl;
  return 0;
}