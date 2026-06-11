#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <algorithm> 
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define F first
#define S second
#define pb push_back
#define pu push
#define COUT(x) cout<<(x)<<"\n"
#define PQ priority_queue<ll>
#define PQR priority_queue<tll,vector<tll>,greater<tll>>
#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define mp make_pair
#define sz(x) (ll)(x).size()
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<ll,ll,ll> tll;
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vstr = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
template<class T> inline bool chmax(T& a, T b) { 
 if (a < b) { a = b; return true; } return false; 
}
template<class T> inline bool chmin(T& a, T b) {
 if (a > b) { a = b; return true; } return false; 
}
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
int main(){
  ll n;
  cin>>n;
  vll p(n);
  vll num(n+1);
  rep(i,n){
    cin>>p[i];
    num[p[i]]=i+1;
  }
  set<ll> s;
  s.insert(0);
  s.insert(n+1);
  s.insert(num[n]);
  ll ans=0;
  for(int i=n-1;i>0;i--){
    auto itr=s.lower_bound(num[i]);
    itr--;
    ll k=*itr;
    ll cu=0;
    if(k!=0){
      itr--;
      ll kk=*itr;
      cu=k-kk;
      itr++;
      itr++;
      ll kkk=*itr;
      ans+=cu*(kkk-num[i])*i;
    }
    itr=s.lower_bound(num[i]);
    k=*itr;
    if(k!=n+1){
      itr++;
      ll kk=*itr;
      ll cu=kk-k;
      itr--;
      itr--;
      ll kkk=*itr;
      ans+=cu*(num[i]-kkk)*i;
    }
    s.insert(num[i]);
  }
  COUT(ans);
}