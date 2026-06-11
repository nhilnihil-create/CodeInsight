#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int N,K;
  cin>>N>>K;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  int roop=K;
  while(roop--){
    vector<int>IMOS(N+1);
    for(int j=0;j<N;j++){
        int l=max(0,j-A[j]);
        int r=min(N,j+A[j]+1);
        IMOS[l]++;IMOS[r]--;
    }
    for(int j=0;j<N;j++){
        IMOS[j+1]+=IMOS[j];
    }
    IMOS.pop_back();
    if(A==IMOS){break;}
    else{A=IMOS;}
  }
  for(int i=0;i<N;i++){
    cout<<A[i]<<endl;
  }
  return 0;  
}