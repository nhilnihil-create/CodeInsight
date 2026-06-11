#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t solve(int64_t left,int64_t right,int64_t n,vector<int64_t> &a,vector<int64_t> &b,int64_t k){
  int64_t mid=(left+right)/2;
  if(mid==left){
    int64_t cnt=0;
    rep(i,n){
      if(a[i]*b[n-i-1]>mid)cnt+=b[n-1-i]-(mid/a[i]);
    }
    if(cnt<=k)return mid;
    else return right;
  }
  int64_t cnt=0;
  rep(i,n){
    if(a[i]*b[n-i-1]>mid)cnt+=b[n-1-i]-(mid/a[i]);
  }
  if(cnt<=k)return solve(left,mid,n,a,b,k);
  else return solve(mid,right,n,a,b,k);
}

int main(){
  int64_t n,k;
  cin >> n >> k;
  vector<int64_t> b(n,0);
  vector<int64_t> a(n,0);
  vector<int> c(n,0);
  rep(i,n) cin >> b[i];
  rep(i,n) cin >> a[i];
  int64_t t=0;
  rep(i,n)t+=b[i];
  if(t<=k){
    cout << 0 << endl;
    return 0;
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  /*rep(i,n){
    c[i]=a[i]*b[n-i-1];
  }*/
  cout << solve(0,1100000000001,n,a,b,k) << endl;
}
