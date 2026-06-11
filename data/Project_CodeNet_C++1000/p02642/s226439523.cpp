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
int n;
cin>>n;
vector<int>a(n);
rep(i,n)cin>>a[i];
sort(a.begin(),a.end());
map<int,int>m;
rep(i,n)m[a[i]]++;
vector<int>an(1000050);
vector<int>furui(1000050,0);
for(auto i:a){
  if(furui[i]==0){
    an[i]=1;
  for(int t=i;t<1000050;t+=i){
    furui.at(t)++;
  }
}
}
int ans=0;
rep(i,n){
  if(m.at(a.at(i))==1&&an[a[i]]==1)ans++;
}
cout<<ans<<endl;
}
