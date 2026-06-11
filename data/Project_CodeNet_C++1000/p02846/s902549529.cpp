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
  ll t1,t2;
  ll a1,a2,b1,b2;
  cin>>t1>>t2>>a1>>a2>>b1>>b2;
  if(a1<b1){
    swap(a1,b1);
    swap(a2,b2);
  }
  if(t1*a1+a2*t2>t1*b1+t2*b2){
    COUT(0);
    return 0;
  }
  else if(t1*a1+a2*t2==t1*b1+t2*b2){
    COUT("infinity");
    return 0;
  }
  else{
    ll u=t1*a1-t1*b1;
    ll d=t1*b1+t2*b2-t1*a1-a2*t2;
    ll ans=(u+d-1)/d*2-1;
    if(u%d==0) ans++;
    COUT(ans);
  }
}