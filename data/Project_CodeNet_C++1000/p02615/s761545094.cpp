#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  sort(A.rbegin(),A.rend());
  int64_t ans=A[0];
  int cnt=N-2;
  for(int i=1;i<N;i++){
    for(int j=0;j<2;j++){
      if(cnt==0){cout<<ans<<endl;return 0;}
      ans+=A[i];
      cnt--;
    }
  }
  return 0;  
}