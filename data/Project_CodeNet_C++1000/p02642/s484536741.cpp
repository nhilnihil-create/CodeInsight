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
  sort(A.begin(),A.end());
  vector<bool>div(1000000,true);
  for(int i=0;i<N;i++){
    if(i>=1&&A[i]==A[i-1]){div[A[i]]=false;continue;}
    for(int j=2;j<=1000000/A[i];j++){
      div[A[i]*j]=false;
    }
  }
  int cnt=0;
  for(int i=0;i<N;i++){
    if(div[A[i]]){cnt++;}
  }
  cout<<cnt<<endl;
  return 0;
}
