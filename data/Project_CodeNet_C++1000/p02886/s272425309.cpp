#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  //以下、O(n)の解法
  ll n;
  cin >> n;
  ll d[n];
  for(ll i=0;i<n;i++)cin >> d[i];

  ll s=0;
  for(ll i=0;i<n;i++)s+=d[i];
  s*=s;
  for(ll i=0;i<n;i++)s-=d[i]*d[i];
  s/=2;
  cout << s << endl;


}