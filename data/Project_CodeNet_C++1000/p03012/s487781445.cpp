#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;

int main(){

  ll n;
  cin >> n;
  ll w[n];
  for(int i=0;i<n;i++)cin >> w[i];

  ll l=inf;
  for(int i=1;i<n;i++){
    ll s1=0,s2=0;
    for(int j=0;j<n;j++){
      if(j<=i)s1+=w[j];
      else s2+=w[j];
    }
    l=min(l,abs(s1-s2));
  }

  cout << l << endl;

}