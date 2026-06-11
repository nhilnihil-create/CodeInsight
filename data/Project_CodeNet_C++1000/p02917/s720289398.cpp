#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod = 1000000007;

int main() {
  int N;
  cin>>N;
  vector<int>B(N-1);
  int sum=0;
  for(int i=0;i<N-1;i++){
    cin>>B[i];
    if(i==0){sum+=B[i];}
    else{sum+=min(B[i],B[i-1]);}
  }
  sum+=B[N-2];
  cout<<sum<<endl;
  return 0;
}