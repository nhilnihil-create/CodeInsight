#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll a[101]={};
  for(ll i=1;i<10;i++){
    for(ll j=1;j<10;j++)a[i*j]=1;
  }

  ll n;
  cin >> n;
  if(a[n]==0)cout << "No" << endl;
  else cout << "Yes" << endl;

}