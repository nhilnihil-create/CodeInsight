#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

vvl memo(2001,vl(2001,-1));
ll choose(ll x,ll y){
  if(memo[x][y]!=-1){
    return memo[x][y];
  }
  else{
    if(x<0||y<0){
      return 0;
    }
    else if(x<y){
      memo[x][y]=0;
      return 0;
    }
    else if(y==0){
      memo[x][y]=1;
      return memo[x][y];
    }
    else if(x==y){
      memo[x][y]=1;
      return 1;
    }
    else{
      memo[x][y]=(choose(x-1,y-1)+choose(x-1,y))%MOD;
      return memo[x][y];
    }
  }
}

int main() {
  ll n,k;
  cin >> n >> k;
  FOR(i,1,k+1){
    cout << choose(n-k+1,i)*choose(k-1,i-1)%MOD << endl;
  }
}