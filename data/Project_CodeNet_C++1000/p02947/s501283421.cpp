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
  ll N;
  cin>>N;
  vector<string> s(N);
  rep(i,N){
    cin>>s[i];
    sort(s[i].begin(),s[i].end());
  }
  ll ans=0;
  ll count=0;
  sort(s.begin(),s.end());
  rep(i,N-1){
    if(s[i]==s[i+1]){
      count++;
      ans+=count;
    }
    else{
      count=0;
    }
  }
  cout<<ans<<endl;
}
