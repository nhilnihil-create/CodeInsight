#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int64_t N,A,B;
  cin>>N>>A>>B;
  int64_t ans=0;
  if(A%2==B%2){ans=abs(A-B)/2;}
  else{ans=min(A-1,N-B)+1+(B-A-1)/2;}
  cout<<ans<<endl;
  return 0;}