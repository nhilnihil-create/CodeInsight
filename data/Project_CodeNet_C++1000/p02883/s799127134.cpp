#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

int n,k;
int A[200000];
int K[200000];

bool check(int x){
  int res = 0;
  rep(i,0,n){
    int need = x/K[i];
    if(need < A[i]) res += A[i]-need;
  }
  return (res <= k);
}

signed main(){
  cin >> n >> k;
  rep(i,0,n) cin >> A[i];
  rep(i,0,n) cin >> K[i];
  sort(A, A+n);
  sort(K, K+n, greater<>());
  int ng = -1;
  int ok = 1e13;
  while(ok - ng > 1){
    int mid = (ok+ng)/2;
    // cout << "a" << mid << " " << check(mid) << endl;
    if(check(mid)) ok = mid;
    else ng = mid;
    // cout << ok << " " << ng << endl;
  }
  cout << ok << endl;
}