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
  vector<int>X(N);
  for(int i=0;i<N;i++){
    cin>>X[i];
  }
  int MIN=INF;
  for(int P=1;P<=100;P++){
    int sum=0;
    for(int i=0;i<N;i++){
      int r=abs(X[i]-P);
      sum+=r*r;
    }
    if(sum<MIN){MIN=sum;}
  }
  cout<<MIN<<endl;
  return 0;  
}