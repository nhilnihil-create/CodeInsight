#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  string N;
  cin >> N;
  vector<vector<ll>> dp(N.size(),vector<ll>(2,0));
  rep(i,(ll)N.size()){
    if(i==0){
      dp.at(i).at(0)=min((N.at(i)-'0'),11-(N.at(i)-'0'));
      dp.at(i).at(1)=min((N.at(i)-'0')+1,10-(N.at(i)-'0'));
    }else{
      dp.at(i).at(0)=min(dp.at(i-1).at(0)+(N.at(i)-'0'),dp.at(i-1).at(1)+10-(N.at(i)-'0'));
      dp.at(i).at(1)=min(dp.at(i-1).at(0)+(N.at(i)-'0')+1,dp.at(i-1).at(1)+9-(N.at(i)-'0'));
    }
  }
  cout << dp.at((ll)N.size()-1).at(0) << endl;
}