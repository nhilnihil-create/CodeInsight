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
  int64_t t=1e18;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  
  for(int i=0;i<N;i++){
    if(A[i]==0){cout<<0<<endl;return 0;}
  }
  int64_t sum=1;
  for(int i=0;i<N;i++){
    if(t%A[i]==0){
      if(sum<=t/A[i]){sum*=A[i];}
      else {cout<<-1<<endl;return 0;}
    }
    else {
      if(sum<t/A[i]){sum*=A[i];}
      else{cout<<-1<<endl;return 0;}
    }
  }
  cout<<sum<<endl;
  return 0;  
}