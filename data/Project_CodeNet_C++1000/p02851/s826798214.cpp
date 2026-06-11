#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include <bits/stdc++.h> 
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

ll l[200020],r[200020],a[200020];

int main(){
  int n;
  cin >> n;
  ll k;
  cin >> k;
  rep(i,n){
    cin >> a[i+1];
    a[i+1]--;
    a[i+1]%=k;
  }
  REP(i,1,n+10)l[i]=(l[i-1]+a[i])%k;
  if(k>=n+1)k=n+1;
  map<ll,ll> mp;
  rep(i,k){
    mp[l[i]]++;
  }
  ll ans=mp[l[0]]-1;
  int cnt=0;
  for(int i=1;i<=n-1;i++){
    cnt++;
    mp[l[i-1]]--;
    if(i+k-1<=n)mp[l[i+k-1]]++;
    ans+=mp[l[i]]-1;
  }
  cout << ans << endl;
return 0;}