#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int ll

main(){
  int n;
  cin>>n;
  vector<int> a(n);
  map<int,int> mp;
  rep(i,n){
    int A; cin>>A;
    a[i]=A;
    mp[A]++;
  }
  map<ll,ll> each;
  ll s=0;
  for(auto x : mp){
    each[x.first]=x.second*(x.second-1)/2;
    s+=each[x.first];
  }
  rep(i,n){
    int A=a[i];
    int ans=s-each[A]+(mp[A]-1)*(mp[A]-2)/2;
    cout<<ans<<endl;
  }
}