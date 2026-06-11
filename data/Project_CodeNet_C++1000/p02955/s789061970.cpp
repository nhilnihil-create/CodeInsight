#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int n,k;cin>>n>>k;
  vector<ll>a(n);
  rep(i, n)cin>>a[i];

  int sum = 0;
  for(auto c:a)sum+=c;

  set<int>candidates;
  for(int i=1;i*i<=sum; i++){
    if(sum%i)continue;

    candidates.insert(i);
    candidates.insert(sum/i);
  }

  int ans = 0;
  for(auto c:candidates){
    vector<ll>aa(n);
    rep(i, n)aa[i] = a[i]%c;
    sort(aa.begin(), aa.end());

    int tot = 0;
    rep(i, n)tot+=aa[i];
    int rcount = tot/c;

    ll rsum=0;
    rep(i, rcount)rsum += c-aa[n-1-i];
    if(rsum <= k)ans = max<ll>(ans, c);
  }

  cout<<ans<<endl;

  return 0;
}
