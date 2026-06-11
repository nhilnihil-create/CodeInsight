#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,ans=0;
  string S;
  cin >> N >> S;
  vector<vector<ll>> A(3,vector<ll>(1000,0));
  rep(i,N){
    for(ll j=2;j>=0;j--){
      if(j==0){
        A.at(j).at(S.at(i)-'0')=1;
      }else{
        rep(k,(ll)pow(10,j)){
          if(A.at(j-1).at(k)==1){
            A.at(j).at(10*k+S.at(i)-'0')=1;
          }
        }
      }
    }
  }
  rep(i,1000){
    if(A.at(2).at(i)==1){
      ans++;
    }
  }
  cout << ans << endl;
}
