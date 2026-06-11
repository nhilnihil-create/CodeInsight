#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  ll a[n+1]={};
  for(int i=1;i<n+1;i++)cin >> a[i];
  ll b[n+1]={};//答え
  vector<ll> d;

  b[n]=a[n];
  if(b[n]==1)d.push_back(n);
  for(int i=n-1;i>0;i--){
    ll c=0;
    ll k=1;
    while(i*k<=n){
      c+=b[i*k];
      k++;
    }
    b[i]=abs(c%2-a[i]);
    if(b[i]!=0)d.push_back(i);
  }

  if(d.empty())cout << 0 << endl;
  else{
    cout << d.size() << endl;
    for(int i=0;i<d.size();i++)cout << d[i] <<" " ;
  }

}