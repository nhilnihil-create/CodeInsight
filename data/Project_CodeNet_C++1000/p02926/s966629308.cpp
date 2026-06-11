#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  ll n;
  cin >> n;
  
  vector<long double> x(n),y(n);
  vector<vector<long double>> v;
  for(ll i=0;i<n;i++){
    cin >> x[i] >> y[i];
    v.push_back({atan2l(y[i],x[i]),x[i],y[i]});
  }
  sort(v.begin(),v.end());

  long double ans=0;
  for(ll i=0;i<n;i++){
    for(ll j=i+1;j<n;j++){
      ll X=0,Y=0;
      for(ll k=i;k<=j;k++){
        X+=v[k][1];
        Y+=v[k][2];
      }
      long double kans=sqrt(X*X+Y*Y);
      ans=max(ans,kans);
      
      X=0,Y=0;
      for(ll k=j;k<n;k++){
        X+=v[k][1];
        Y+=v[k][2];
      }
      for(ll k=0;k<=i;k++){
        X+=v[k][1];
        Y+=v[k][2];
      }
      kans=sqrt(X*X+Y*Y);
      ans=max(ans,kans);
    }
  }
  //cout << ans << endl;

  for(ll i=0;i<n;i++){
    long double kans=sqrt(x[i]*x[i]+y[i]*y[i]);
    ans=max(ans,kans);
  }

  printf("%0.20Lf\n",ans);

}