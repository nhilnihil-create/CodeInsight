#include<bits/stdc++.h>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;

int main()
{
  int N;
  cin >> N;
  int A[100010];
  
  rep(i,N) cin >> A[i];
  sort(A,A+N);

  int M = 0;
  int ans[100010][2];
  int y;
  int x;
  
  x = A[N-1];
  y = A[0];
  rep(i,1,N-1){
    if(A[i]<0){
      ans[i-1][0] = x;
      ans[i-1][1] = A[i];
      x -= A[i];
    }else{
      ans[i-1][0] = y;
      ans[i-1][1] = A[i];
      y -= A[i];
    }
  }
  ans[N-2][0] = x;
  ans[N-2][1] = y;
  M = x-y;
  
  cout << M << endl;
  rep(i,N-1){
    cout << ans[i][0] << " " << ans[i][1] << endl;
  }
}
