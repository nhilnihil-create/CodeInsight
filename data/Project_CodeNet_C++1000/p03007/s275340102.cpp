#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<endl
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,vector<ll>,greater<ll>>
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define mp make_pair
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define sz(x) (int)(x).size()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using pll = pair<ll, ll>;
using vc = vector<char>;
using vvc = vector<vc>;
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main(){
  ll n;
  cin>>n;
  vll a(n);
  rep(i,n) cin>>a[i];
  sort(all(a));
  ll ans=a[n-1];
  ans-=a[0];
  vll h(0);
  vll m(0);
  for(int i=1;i<n-1;i++){
    if(a[i]<0) {
      ans-=a[i];
      m.pb(a[i]);
    }
    else{
      ans+=a[i];
      h.pb(a[i]);
    }
  }
  COUT(ans);
  ll cu=a[0];
  rep(i,sz(h)){
    cout<<cu<<" "<<h[i]<<endl;
    cu-=h[i];
  }
  ll kk=a[n-1];
  rep(i,sz(m)){
    cout<<kk<<" "<<m[i]<<endl;
    kk-=m[i];
  }
  cout<<kk<<" "<<cu<<endl;
}
