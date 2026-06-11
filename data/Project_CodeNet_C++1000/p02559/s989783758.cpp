#include<bits/stdc++.h>
#include <atcoder/all>
#define ll long long int
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;
using namespace atcoder;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  ll n,q;
  cin >> n >>q;
  vec a(n);
  for(ll i=0;i<n;i++)cin >> a[i];

  fenwick_tree<ll> T(n);
  for(ll i=0;i<n;i++)T.add(i,a[i]);
  
  for(ll i=0;i<q;i++){
    ll c,p,x;
    cin >> c >> p >> x;
    if(c==0)T.add(p,x);
    else cout << T.sum(p,x) << endl;
  }

}