#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int mod=1e9+7;
int main() {
  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  vector<int>hat(1000005);
  hat[0]=3;
  int64_t sum=1;
  for(int i=0;i<N;i++){
    (sum*=hat[A[i]])%=mod;
    hat[A[i]]--;
    hat[A[i]+1]++;
  }
  cout<<sum<<endl;
  return 0;  
}