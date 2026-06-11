#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  vector<ll> res(n);
  vector<ll> res2(n);
  rep(i,n){
    cin>>a[i];
    if(i>=a[i]) res[i-a[i]]++;
    if(i+a[i]<n) res2[i+a[i]]++;
  }
  ll ans=0;
  rep(i,n){
    ans+=res[i]*res2[i];
  }
  cout<<ans<<endl;
}