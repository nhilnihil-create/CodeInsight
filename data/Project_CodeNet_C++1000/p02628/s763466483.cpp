#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int N,K;
  cin>>N>>K;
  vector<int>p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  sort(p.begin(),p.end());
  int sum=0;
  for(int i=0;i<K;i++){
     sum+=p[i];
  }
  cout<<sum<<endl;
  return 0;  
}