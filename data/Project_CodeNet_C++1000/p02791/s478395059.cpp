#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  ll m=inf;
  ll c=0;
  for(ll i=0;i<n;i++){
    ll p;
    cin >> p;
    if(p<=m)c++;
    m=min(m,p);
  }

  cout << c << endl;

}