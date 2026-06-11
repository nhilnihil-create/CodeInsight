#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  string L;
  cin >> L;
  vector<ll> dp1(L.size()),dp2(L.size());
  dp1.at(0)=1;
  dp2.at(0)=2;
  rep(i,L.size()-1){
    if(L.at(i+1)=='1'){
      dp1.at(i+1)=3*dp1.at(i)+dp2.at(i);
      dp2.at(i+1)=2*dp2.at(i);
      dp1.at(i+1)%=MOD;
      dp2.at(i+1)%=MOD;
    }else{
      dp1.at(i+1)=3*dp1.at(i);
      dp2.at(i+1)=dp2.at(i);
      dp1.at(i+1)%=MOD;
      dp2.at(i+1)%=MOD;
    }
  }
    cout << (dp1.at(L.size()-1)+dp2.at(L.size()-1))%MOD << endl;
}