
#include <bits/stdc++.h>  
using namespace std;

typedef long long ll;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);	
  ll n;
  cin>>n;
  vector<ll> arr(n+1);
  for(ll i=1;i<=n;i++)
    cin>>arr[i];
  vector<ll> ans(n+1);
  for(ll i=n;i;i--){
    ll sum=0;
  	for(ll j = 2*i;j<=n;j+=i)
      if(ans[j])
        sum++;
    if(arr[i]%2 != sum%2)
      ans[i]=1;
  }
  vector<ll> fin;
  for(ll i=1;i<=n;i++)
    if(ans[i])
      fin.push_back(i);
  cout<<fin.size()<<endl;
  for(auto i:fin)
    cout<<i<<" ";
cout<<endl;
    return 0;
}