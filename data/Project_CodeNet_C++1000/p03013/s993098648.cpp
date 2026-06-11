#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const long long INF =1ll<<60;
const int DAM =-1;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N,M;
  cin>>N>>M;
  
  vector<int> dp(N+2,0);
  vector<int> broken(N+1,0);
  for(int i=0;i<M;i++){
    int a;
    cin>>a;
    broken.at(a)=1;
  }
  dp.at(0)=1;
  if (broken.at(1))
    dp.at(1) = 0;
  else
    dp.at(1) = 1;
  for(int i=2;i<=N;i++){
    if(broken.at(i)!=1){
      dp.at(i)=(dp.at(i-2)+dp.at(i-1))%mod;

    }
  }
  cout<<dp.at(N)<<endl;
    
}