#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
  ll n,q;
  cin>>n>>q;
  vll tree(n+1,vl(0));
  rep(i,n-1){
      ll a,b;
      cin>>a>>b;
      tree[a].pb(b);
      tree[b].pb(a);
  }
  vl points(n+1,0);
  rep(i,q){
      ll p,x;
      cin>>p>>x;
      points[p]+=x;
  }
  vector<bool> z(n+1,false);
  queue<ll> Q;
  Q.push(1);
  while(!Q.empty()){
      ll num=Q.front();
      Q.pop();
      z[num]=true;
      rep(i,sz(tree[num])){
          if(!z[tree[num][i]]){
              points[tree[num][i]]+=points[num];
              Q.push(tree[num][i]);
          }
      }
  }
  for(ll i=1;i<=n;i++){
      cout<<points[i]<<" ";
  }
  cout<<endl;
}
