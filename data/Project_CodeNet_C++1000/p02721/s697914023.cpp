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

int main() {
  ll n,k,c;
  cin >> n >> k >> c;
  string s;
  cin >> s;
  vl dp_L(k,-1),dp_R(k,-1);
  ll i=0,j=0;
  while(i<n&&j<k){
    if(s[i]=='o'){
      dp_L[j]=i;
      j++;
      i +=c+1;
    }
    else
      i++;
  }
  i=n-1,j=k-1;
  while(i>=0&&j>=0){
    if(s[i]=='o'){
      dp_R[j]=i;
      j--;
      i -=c+1;
    }
    else
      i--;
  }
  bool a=false;
  rep(i,k){
    if(dp_L[i]==dp_R[i]){
      a=true;
      dp_L[i]++;
      cout << dp_L[i] << endl;
    }
  }
}