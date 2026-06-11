#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pi 3.14159265359
#define all(i) i.begin(),i.end()
using namespace std;
const long long INF=1e9+7;
const string alp="abcdefghijklmnopqrstuvwxyz"; //26
const string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=998244353LL;
//const ll MOD=1777777777LL;


int main() {
  ll N;
  cin>>N;
  vl a(N);
  vl count(1000010,0);
  ll ma=0;
  rep(i,N){
    cin>>a[i];
    ma=max(a[i],ma);
    count[a[i]]++;
  }
  sort(all(a));
  ll ans=0;
  vector<bool> judge(1000010,true);
  for(int i=0;i<N;i++){
    if(judge[a[i]]&&count[a[i]]==1){
      ans++;
    }
      for(int j=a[i];j<=ma;j+=a[i]){
        judge[j]=false;
      }
  }
  cout<<ans<<endl;
}
