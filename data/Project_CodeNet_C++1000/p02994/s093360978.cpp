#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,l;
  cin >> n >> l;

  ll s=0;
  for(int i=1;i<n+1;i++)s+=l+i-1;

  if(l+n-1<0)cout << s-(l+n-1) << endl;
  else if(l>0)cout << s-l << endl;
  else cout << s << endl;

}