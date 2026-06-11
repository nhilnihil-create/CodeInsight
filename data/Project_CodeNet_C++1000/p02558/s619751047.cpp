#include<bits/stdc++.h>
#include <atcoder/dsu>

using namespace std;
using namespace atcoder;
	
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define mp make_pair
	
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
	
const int mod=1e9+7;
	
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
int mul(int a,int b)
{
  return ((a)*1ll*(b))%mod;
}
	
void add(int &a,int b)
{
  a+=b;
  if(a>=mod)a-=mod;
}

int sub(int a,int b){
  a-=b;
  if(a<0){
    a+=mod;
  }
  return a;
}

int powz(int a,int b){
  int res=1;
  while(b){
    if(b&1){
      res=mul(res,a);
    }
    b/=2;
    a=mul(a,a);
  }
  return res;
}

template <typename A, typename B>
istream& operator>>(istream& input,pair<A,B>& x) {
  input>>x.F>>x.S;
  return input;
}

template <typename A>
istream& operator>>(istream& input,vector<A>& x) {
  for(auto& i:x)
    input>>i;
  return input;
}

template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {
  for(auto& i:x)
	  output<<i<<' ';
	return output;
}

const int N=1000002;

void solve(){
  int n,q;
  cin>>n>>q;
  dsu d(n);
  while(q--){
    int tmp;
    cin>>tmp;
    int x,y;
    cin>>x>>y;
    if(tmp==0){
      d.merge(x,y);
    }
    else{
      if(d.same(x,y)){
	cout<<1;
      }
      else{
	cout<<0;
      }
      cout<<'\n';
    }
  }
  
  
}
	
signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc=1;
  // cin>>tc;
  for(int _=0;_<tc;_++){
    // cout<<"Case #"<<_+1<<": ";
    solve();
    if(_!=tc-1)
      cout<<"\n";
  }
}
