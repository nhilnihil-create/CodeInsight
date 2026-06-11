#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<int>A(N+1),B(N);
  for(int i=0;i<N+1;i++){
    cin>>A[i];
  }
  for(int i=0;i<N;i++){
    cin>>B[i];
  }
  int64_t sum=0;
  for(int i=0;i<N;i++){
    if(A[i]<=B[i]){
      sum+=A[i];
      int sp=B[i]-A[i];
      A[i]=0;
      if(A[i+1]<=sp){
        sum+=A[i+1];
        A[i+1]=0;
      }
      else{
        A[i+1]-=sp;
        sum+=sp;
      }
    }
    else{
      sum+=B[i];
      A[i]-=B[i];
    }
  }
  cout<<sum<<endl;
  return 0;
}