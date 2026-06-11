#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m,ans=0;cin>>n>>m;
  lvector A(n,0);rep(i,n) cin>>A[i];
  ll num_of_2=0,tmp;
  while(A[0]%2==0) {num_of_2++;A[0]/=2;}
  bool isok=true;
  for(ll i=1;i<n;++i) {
    tmp=0;
    while(A[i]%2==0) {tmp++;A[i]/=2;}
    if(num_of_2!=tmp) {isok=false;break;}
  }
  if(isok) {
    sort(ALL(A));
    ll lcm=A[0];
    for(ll i=1;i<n;++i) lcm=(lcm*A[i])/__gcd(lcm,A[i]);
    rep(i,num_of_2-1) lcm*=2;
    ans+=(m/lcm+1)/2;
  }
  print(ans);
  return 0;
}