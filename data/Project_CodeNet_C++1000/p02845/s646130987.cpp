#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

const int MOD=1e9+7;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  vector<int> cnt(n,3);
  vector<int> used(n,0);
  ll ans=1;
  rep(i,n){
    if(a[i]==0) ans*=cnt[a[i]];
    else {ans*=used[a[i]-1];used[a[i]-1]--;}
    ans%=MOD;
    used[a[i]]++;
    cnt[a[i]]--;
  }
  cout<<ans<<endl;
}