#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,d;
  cin >> n>> d;
  long double x[n][d];
  for(int i=0;i<n;i++){
    for(int j=0;j<d;j++)cin >> x[i][j];
  }

  ll s=0;

  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      long double t=0;
      for(int k=0;k<d;k++)t+=(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
      t=sqrt(t);
      if(abs(t-floor(t))<0.00001)s++;
    }
  }
  cout << s << endl;

}