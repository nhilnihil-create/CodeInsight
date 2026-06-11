#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;
static const ll LOGN=55;


int main(void) {
  ll N;
  cin >> N;
  ll i;
  map<string, ll> mp;
  ll t[1111];
  ll sum[1111]={};
  
  string s;
  for(i=1; i<=N; i++) {
    cin >> s >> t[i];
    mp[s]=i;
    sum[i]=sum[i-1]+t[i];
  }
  
  string X;
  cin >> X;
  pt(sum[mp[s]]-sum[mp[X]]);
  
}



