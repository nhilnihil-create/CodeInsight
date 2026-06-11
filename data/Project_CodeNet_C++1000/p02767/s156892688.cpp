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
  int ans=INF;
  for(int p=1;p<=100;p++){
    int sum=0;
    for(int i=0;i<N;i++){
      sum+=(p-X[i])*(p-X[i]);
    }
    chmin(ans,sum);
  }
  cout<<ans<<endl;
  return 0;  
}