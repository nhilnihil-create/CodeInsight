#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  ll a[n+1];
  for(int i=0;i<n+1;i++)cin >> a[i];
  ll b[n];
  for(int i=0;i<n;i++)cin >> b[i];

  ll c=0;
  for(int i=0;i<n;i++){
    if(a[i]>=b[i]){
      c+=b[i];
    }
    else if(b[i]<a[i]+a[i+1]){
      c+=b[i];
      a[i+1]=a[i+1]-(b[i]-a[i]);
    }
    else{
      c+=a[i]+a[i+1];
      a[i+1]=0;
    }
  }

  cout <<c << endl;

}