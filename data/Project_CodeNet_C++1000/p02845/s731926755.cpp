#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1000000000+7;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;++i) cin >> a[i];

  vector<int> x(n+1,0),y(n+1,0),z(n+1,0);
  for(int i=0;i<n;++i){
    if(x[i]==a[i]){
      x[i+1]=x[i]+1;
      y[i+1]=y[i];
      z[i+1]=z[i];
      //cout << x[i] << " ";
    }else if(y[i]==a[i]){
      x[i+1]=x[i];
      y[i+1]=y[i]+1;
      z[i+1]=z[i];
      //cout << y[i] << " ";
    }else if(z[i]==a[i]){
      x[i+1]=x[i];
      y[i+1]=y[i];
      z[i+1]=z[i]+1;
      //cout << z[i] << " ";
    }else{
      cout << "0" << endl;
      //cout << i << endl;
      return 0;
    }
  }
  ll ans=1;
  for(int i=0;i<n;++i){
    int cnt=0;
    if(a[i]==x[i])cnt++;
    if(a[i]==y[i])cnt++;
    if(a[i]==z[i])cnt++;
    ans=(ans*cnt)%MOD;
  }
  cout << ans << endl;
}
