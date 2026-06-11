#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000
int MOD=1000000007;
struct edge {
    int to, cost;
};

int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}

int gyaku(int n){
    return modpow(n,MOD-2);
}

map<int,int> factor(int n){
  map<int,int>res;
  for(int i=2;i*i<=n;i++){
      for(; n%i==0;n/=i) res[i]++;
  }
  if(n>1)res[n]++;
  return res;
}
////////////////////////////////////////////////////////////
signed main() {
int x,y,a,b,c;
cin>>x>>y>>a>>b>>c;
vector<int>p(a),q(b),r(c);
rep(i,a)cin>>p[i];
rep(i,b)cin>>q[i];
rep(i,c)cin>>r[i];
sort(p.begin(),p.end());
sort(q.begin(),q.end());
sort(r.begin(),r.end());
reverse(p.begin(),p.end());
reverse(q.begin(),q.end());
reverse(r.begin(),r.end());
int red=0;int mu=0;int green=0;
int ans=0;
while(red+mu+green<x+y){
  if(red==x){
    if(q[green]>=r[mu]){ans+=q[green];green++;}
    else {ans+=r[mu];mu++;}
  }
  else if(green==y){
    if(p[red]>=r[mu]){ans+=p[red];red++;}
    else{ans+=r[mu];mu++;}
  }
  else{
    if(p[red]>=r[mu]&&p[red]>=q[green]){ans+=p[red];red++;}
    else if(r[mu]>=p[red]&&r[mu]>=q[green]){ans+=r[mu];mu++;}
    else {ans+=q[green];green++;}
  }
  }

cout<<ans<<endl;
}
