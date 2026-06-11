#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) {
    int x;
    cin >> x;
    a[x-1]++;
  }
  sort(a.begin(),a.end());
  vector<int> s(n+1,0);
  s[0]=0;
  rep(i,n){
    s[i+1]=s[i]+a[i];
  }
  for(int k=1;k<=n;k++){
  //  cout<<k<<endl;

    ll l=0;
    ll r=n+1;
    while(l+1<r){
      ll c=(l+r)/2;
      ll id=lower_bound(a.begin(),a.end(),c)-a.begin();
      ll sum=s[id]+c*(n-id);
    //  cout<<id<<"id"<<sum<<"sum"<<(c*k)<<"c"<<l<<"l"<<r<<"r"<<endl;
      if(sum<c*k){
        r=c;
      }
      else l=c;
    //  cout<<l<<"l"<<r<<"r"<<endl;

    }
    cout<<l<<endl;

  }
}
