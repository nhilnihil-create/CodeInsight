#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

ll choose2(ll n){
  return n*(n-1)/2;
}
 
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  vector<int> cnt(n);
  rep(i,n) cin>>a[i];
  rep(i,n) a[i]--;
  ll tot=0;
  rep(i,n) cnt[a[i]]++;
  rep(i,n) tot+=choose2(cnt[i]);
  rep(i,n){
    ll ans=tot;
    ans-=choose2(cnt[a[i]]);
    cnt[a[i]]--;
    ans+=choose2(cnt[a[i]]);
    cnt[a[i]]++;
    cout<<ans<<endl;
  }
}