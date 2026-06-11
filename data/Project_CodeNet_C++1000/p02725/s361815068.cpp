#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int K,N;
  cin>>K>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  vector<int64_t>dist;
  dist.push_back(A[0]+K-A[N-1]);
  for(int i=0;i<N-1;i++){
     dist.push_back(A[i+1]-A[i]);
  }
  int mx=*max_element(dist.begin(),dist.end());
  cout<<K-mx<<endl;
  return 0;  
}