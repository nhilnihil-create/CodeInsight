#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<=(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<ll> vl;
typedef vector<bool> vb;
const ll INF=1LL << 60;
const ll MOD=1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vb t(n+1, true);
  rep(i ,m){
    int a;
    cin >> a;
    t[a]=false;
  }

  vl dp(100010, 0);
  dp[0]=1;
  rep(i, n)for(int j=i+1; j<=min(n, i+2); j++){
    if(t[j]){
      dp[j]+=dp[i];
      dp[j]%=MOD;
    }
  }

  cout << dp[n] << endl;

  return 0;
}