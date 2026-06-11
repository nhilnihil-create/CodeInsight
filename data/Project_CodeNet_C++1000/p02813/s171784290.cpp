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
  vector<int>P(N),Q(N),A(N);
  for(int i=0;i<N;i++){
    cin>>P[i];
  }
  for(int i=0;i<N;i++){
    cin>>Q[i];
  }
  for(int i=0;i<N;i++){
    A[i]=i+1;
  }
  int cnt=0;
  int a=0,b=0;

  do{
    if(A==P){a=cnt;}
    if(A==Q){b=cnt;}
    cnt++;
  }while(next_permutation(A.begin(),A.end()));

  cout<<abs(a-b)<<endl;
  return 0;  
}