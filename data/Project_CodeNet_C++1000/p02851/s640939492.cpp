#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const ll INF = 1e18;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  vector<ll> s(n);

  rep(i,n){
    cin>>a[i];
    a[i]--;
  }
  s[0]=a[0]%k;
  rep(i,n-1){
    s[i+1]=s[i]+a[i+1];
    s[i+1]%=k;
  }
  map<ll,ll>mp;
  mp[0]++;
  ll cnt=0;
  rep(i,n){
    if (i==k-1)mp[0]--;
    if (i>=k){
      mp[s[i-k]]--;
    }
    cnt+=mp[s[i]];
  //  cout<<s[i]<<'s'<<cnt<<'c'<<i<<'i'<<endl;
    mp[s[i]]++;

  }
cout<<cnt;

}
