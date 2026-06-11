#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define DBG_N(hoge) cerr<<" "<<(hoge)<<endl;
#define DBG cerr<<"!"<<endl;
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
ll rui[222222];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,k;cin>>n>>k;
  ll ans=0;
  vi A(n);
  for(auto &a:A){cin>>a;a--;}
  for(int i=1;i<=n;i++){
    rui[i]+=rui[i-1]+A[i-1];
  }
  map<ll,ll>cnt;
  for(int i=0;i<n+1;i++){
    if(i >= k)cnt[rui[i-k]%k]--;
    ans += cnt[rui[i]%k];
    cnt[rui[i]%k]++;
  }
  cout<<ans<<endl;
  return 0;
}
