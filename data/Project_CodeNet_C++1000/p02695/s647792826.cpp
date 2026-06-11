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
int n,m,q;
vector<int>h(11),a(51),b(51),c(51),d(51);
int ans=0;
void dfs(int pos,int last){
  if(pos==n){
    int t=0;
    rep(i,q){
    if(h[b[i]]-h[a[i]]==c[i])t+=d[i];
  }
  ans=max(t,ans);
  return;
}

  h[pos]=last;
  if(pos!=n-1){
    for(int i=last;i<=m;i++){
    dfs(pos+1,i);
  }
}
  else dfs(pos+1,last);

}


signed main() {
cin>>n>>m>>q;
rep(i,q){cin>>a[i]>>b[i]>>c[i]>>d[i];a[i]--;b[i]--;}
for(int i=1;i<=m;i++){
  dfs(0,i);
}
cout<<ans<<endl;
}
