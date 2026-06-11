#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int l,r;
  cin>>l>>r;

  int p = l % 2019;
  int q = r - l + 1;
  if (q >= 2019){
    cout<<0<<endl;
    return 0;
  }
  vector<int> a(q);
  rep(i,q){
    a[i] = (p + i) % 2019;
  }
  int ans = 1e9;
  rep(i,q)rep(j,q){
    if (i!=j)
      ans = min(ans, a[i]*a[j]%2019);
  }
  cout<<ans<<endl;
}