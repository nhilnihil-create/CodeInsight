#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main() {
  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  int64_t money=1000;
  int64_t stock=0;
  for(int i=0;i<N-1;i++){
    if(A[i+1]>A[i]){
      stock+=money/A[i];
      money%=A[i];
      money+=A[i+1]*stock;
      stock=0;
    }
  }
  cout<<money<<endl;
  return 0;
}