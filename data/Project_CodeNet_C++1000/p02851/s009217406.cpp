#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  ll n,k,a[200010],s[200010],i;
  cin >> n >> k;
  for(i=0;i<n;i++){
    cin >> a[i];
  }
  s[0]=0;
  for(i=0;i<n;i++){
    s[i+1]=s[i]+a[i];
    s[i+1]=s[i+1]%k;
  }
  ll x[200010];
  map<ll,ll> mp;
  for(i=0;i<n+1;i++){
    x[i]=s[i]+n-i;
    x[i]=x[i]%k;
    mp[x[i]]++;
  }
  ll ans=0;
  for(i=0;i<n;i++){
    if(mp[x[i]]!=0){
      ans+=mp[x[i]]*(mp[x[i]]-1)/2;
      mp[x[i]]=0;
    }
  }
  ll ans1=0;
  map<ll,ll> mp1;
  for(i=k;i<n+1;i++){
    mp1[x[i]]++;
  }
  for(i=0;i<=n-k;i++){
    if(mp1[x[i]]!=0){
      ans1+=mp1[x[i]];
    }
    mp1[x[i+k]]--;
  }
  cout << ans-ans1 << endl;
}