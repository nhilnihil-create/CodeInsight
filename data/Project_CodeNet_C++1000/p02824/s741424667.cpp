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
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
ll n,m,v,p;

vi A;
bool check(ll mid){
  if(A[p-1] > mid)return false;
  ll num = v*m;
  num -= (p-1)*m;
  for(ll i=p-1;i<n;i++){
    num -= min(m,mid-A[i]);
  }
  return num<=0;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n>>m>>v>>p;
  A.resize(n);
  for(auto &a:A)cin>>a;
  sort(ALL(A),greater<ll>());
  ll le = -1,ri = llINF;
  while(ri-le > 1){
    ll mid = ri+le;
    mid/=2;
    if(check(mid)){
      ri = mid;
    }else{
      le = mid;
    }
  }
  ll ans = 0;
  for(auto a:A)ans += (a+m >= ri);
  //  cout<<le<<" "<<ri<<endl;
  cout<<ans<<endl;
  return 0;
}
