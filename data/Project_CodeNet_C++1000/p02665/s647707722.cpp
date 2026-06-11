#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  int n;
  cin >> n;
  vector<ll> a(n+1);
  for(int i=0;i<n+1;++i){
    cin >> a[i];
  }

  vector<ll> mat(n+1),mit(n+1),t(n+1);
  t[n]=a[n];
  if(n==0){
    if(a[0]==1){
      cout << '1' << endl;
    }else{
      cout << "-1" << endl;
    }
    return 0;
  }
  for(int i=n-1;i>=0;--i){
    if(i==n-1){
      mat[i]=a[n]+a[i];
      mit[i]=(a[n]+1)/2+a[i];
    }else{
      mat[i]=mat[i+1]+a[i];
      mit[i]=(mit[i+1]+1)/2+a[i];
    }
  }
  if(mit[0]>1 || mat[0]<1){
    cout << "-1" << endl;
    return 0;
  }
  t[0]=1;
  vector<ll> ans(n+1);
  ans[0]=1;
  ans[n]=a[n];
  for(int i=1;i<n;++i){
    ll ma=t[i-1]*2;
    ans[i]=min(ma,mat[i]);
    t[i]=ans[i]-a[i];
  }
  ll cal=0;
  for(int i=0;i<=n;++i) cal+=ans[i];
  cout << cal << endl;
  return 0;
}
