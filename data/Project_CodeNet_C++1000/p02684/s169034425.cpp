#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
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
////////////////////////////////////////////////////////////

signed main() {
  int n,k;
  cin>>n>>k;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  vector<int>visited(n+1);
  vector<int>jun(0);
  int syokou=0,kousa=0;
  int next=0,time=0;
  while(kousa==0){
    if(visited[next]==0){
    visited[next]=time;
    jun.push_back(next+1);
  }
    else {
      kousa=time-visited[next];
      syokou=visited[next];
      jun.push_back(next+1);
    }
    next=a[next]-1;
    time++;
  }
  if(k>=syokou)cout<<jun[(k-syokou)%kousa+syokou]<<endl;
  else cout<<jun[k]<<endl;
}
