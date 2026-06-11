#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  ll d[n];
  for(int i=0;i<n;i++)cin >> d[i];

  ll s=0;

  for(ll i=0;i<n-1;i++){
    for(ll j=i+1;j<n;j++){
      s+=d[i]*d[j];
    }
  }

  cout << s << endl;


}