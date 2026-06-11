#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pi 3.14159265359
using namespace std;
const long long INF=1e9+7;
const string alp="abcdefghijklmnopqrstuvwxyg"; //26
const string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYG";
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=998244353LL;
//const ll MOD=1777777777LL;


int main() {
  ll N,K,Q;
  cin>>N>>K>>Q;
  vl a(Q);
  rep(i,Q) cin>>a[i];
  vl score(N,0);
  string ans[N];
  for(int i=0;i<Q;i++){
    score[a[i]-1]++;
  }
  for(int i=0;i<N;i++){
    if(K+score[i]-Q>0){
      ans[i]="Yes";
    }
    else{
      ans[i]="No";
    }
  }
  for(int i=0;i<N;i++){
    cout<<ans[i]<<endl;
  }
}