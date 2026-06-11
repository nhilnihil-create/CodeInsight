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
  vector<int>A(N+1);
  for(int i=1;i<=N;i++){
    cin>>A[i];
  }
  map<int,int>k;
  int64_t  cnt=0;
  for(int j=1;j<=N;j++){
    cnt+=k[j-A[j]];
    k[j+A[j]]++;
  }
  cout<<cnt<<endl;
  return 0;                       
}