#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  int n;
  cin>>n;
  ll a[200005];
  rep(i,n) cin>>a[i];

  ll ma;
  ll ans=0;
  rep(i,n){
    if(i==0||ma<=a[i]){
      ma=a[i];
    }
    else{
      ans+=ma-a[i];
    }
  }
  cout<<ans<<endl;
  return 0;
}
