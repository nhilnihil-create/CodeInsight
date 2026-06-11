#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,m,n) for(int i=m;i<n;i++)

int main() {
  int n;
  ll k;
  cin>>n>>k;
  int a[n];
  rep(i,0,n) cin>>a[i];
  int sum=0;
  rep(i,0,n) sum+=a[i];
  vector<int> res;
  for(int i=1;i*i<=sum;i++){
    if(sum%i==0){
      res.push_back(i);
      if(i!=sum/i) res.push_back(sum/i);
    }
  }
  sort(res.begin(),res.end());
  reverse(res.begin(),res.end());
  
  int i=0;
  while(true){
    int b=res[i];
    ll cur=0;
    int c[n];
    rep(i,0,n){
      int d=a[i]%b;
      cur+=d;
      c[i]=d;
    }
    sort(c,c+n);
    reverse(c,c+n);
    int e=cur/b;
    rep(i,0,e) cur-=c[i];
    if(cur<=k){
      cout<<b<<endl;
      break;
    }
    i++;
  }
}
