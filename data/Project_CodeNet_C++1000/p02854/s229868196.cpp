#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
  ll n;
  cin>>n;
  vector<ll> a(n);
  ll sum=0;
  rep(i,n){
    cin>>a[i];
    sum+=a[i];
  }
  ll cnt=0,ans=100000000000;
  ll sum2=0;
  rep(i,n){
    cnt=0;
    sum2+=a[i];
    cnt=abs(sum2-(sum-sum2));
    ans=min(ans,cnt);
  }
  cout<<ans<<endl;
}