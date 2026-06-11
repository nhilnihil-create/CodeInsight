//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>>vvi;
const ll MOD=1000000007LL;
int main(){
  ll n;
  cin>>n;
  vector<ll>a(n);
  rep(i,n)cin>>a[i];
  vector<ll>vec(3,-1);
  ll ans=1;
  rep(i,n){
    bool once=true;
    int count=0;
    rep(j,3){
      if(a[i]-1==vec[j]){
        count++;
        if(once){
          vec[j]=a[i];
          once=false;
        }
      }
    }
    ans*=count;
    ans%=MOD;
  }
  cout<<ans<<endl;
}
      