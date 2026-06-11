#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int N;
  cin>>N;
  vector<int64_t>A(N);
  int64_t right=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    right+=A[i];
  }
  int64_t left=0;int64_t ans=9999999999999;
  for(int i=0;i<N;i++){
    left+=A[i];right-=A[i];
    if(abs(right-left)<ans){ans=abs(right-left);}
  }
  cout<<ans<<endl;
  return 0;
}