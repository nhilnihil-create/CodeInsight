#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod = 1000000007;

int main(){
  int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  int64_t fact=1;
  int64_t ans=0;
  for(int i=0;i<60;i++){
    int64_t cnt0=0,cnt1=0;
    for(int i=0;i<N;i++){
      if(A[i]%2==1){cnt1++;}
      else{cnt0++;}
      A[i]/=2;
    }
    (ans+=cnt0*cnt1%mod*fact%mod)%=mod;
    (fact*=2)%=mod;
  }
  cout<<ans<<endl;
  return 0;                       
}