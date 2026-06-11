#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
   ll ans= n*(n-1);
  if(ans==0)
    ans=0;
  else
    ans=ans/2;
 
    cout<<ans;
}