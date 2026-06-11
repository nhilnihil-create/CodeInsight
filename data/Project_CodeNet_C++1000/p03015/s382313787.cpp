#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MOD 1000000007

int main(){
  string S;
  cin>>S;
  int N=S.size();
  vector<int> a(N);
  for(int i=0;i<N;i++){
    a.at(i)=S.at(i)-'0';
  }
  vector<vector<ll>> dp(N,vector<ll>(2,0));
  dp.at(0).at(0)=2;
  dp.at(0).at(1)=1;
  for(int i=1;i<N;i++){
    if(a.at(i)==1){
      dp.at(i).at(1)=dp.at(i-1).at(0)+3*dp.at(i-1).at(1);
      dp.at(i).at(0)=2*dp.at(i-1).at(0);
    }else{
      dp.at(i).at(1)=3*dp.at(i-1).at(1);
      dp.at(i).at(0)=dp.at(i-1).at(0);
    }
    dp.at(i).at(0)%=MOD;
    dp.at(i).at(1)%=MOD;
  }
  cout<<(dp.at(N-1).at(0)+dp.at(N-1).at(1))%MOD<<endl;
}
