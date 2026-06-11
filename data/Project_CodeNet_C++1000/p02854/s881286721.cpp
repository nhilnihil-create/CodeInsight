#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin>>n;
  ll a[200010];
  a[0]=0;
  rep(i,n){
    ll A;
    cin>>A;
    a[i+1]=a[i]+A;
  }
  ll min_ans=9090909090;
  rep(i,n){
    ll ans;
    ans=abs(a[i]-(a[n]-a[i]));
    min_ans=min(min_ans,ans);
  }
  cout<<min_ans<<endl;
}