#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define fi first
#define se second
#define INF 1000000009
#define LLINF 1000000000000000009LL
using ll = long long;

vector<int>divisor(int n){
  vector<int>d;
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      d.push_back(i);
      if(i!=n/i)d.push_back(n/i);
    }
  }
  sort(d.begin(),d.end());
  return d;
}

int main(){
  int n,k;
  cin>>n>>k;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  int sum=0;
  rep(i,n)sum+=a[i];
  vector<int>d=divisor(sum);
  int ans=1;
  for(auto x:d){
    vector<int>a_mod(n);
    rep(j,n)a_mod[j]=a[j]%x;
    sort(a_mod.rbegin(),a_mod.rend());
    int s_mod=0;
    rep(j,n)s_mod+=a_mod[j];
    int cnt=0;
    rep2(j,s_mod/x,n){
      cnt+=a_mod[j];
    }
    if(cnt<=k)ans=x;
  }
  cout<<ans<<endl;
  return(0);
}
