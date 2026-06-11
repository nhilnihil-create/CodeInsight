#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll> 
#define ALL(a) a.begin(),a.end()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  lvector A(n,0);rep(i,n) cin>>A[i];
  vector<P> v;
  sort(ALL(A));
  ll maximum=A[n-1],mimimum=A[0];
  for(ll pos=1;pos<n-1;pos++) {
    if(A[pos]>=0) {
      v.emplace_back(P(mimimum,A[pos]));
      mimimum-=A[pos];
    }
    else {
      v.emplace_back(P(maximum,A[pos]));
      maximum-=A[pos];
    }
  }
  v.emplace_back(maximum,mimimum);
  print(maximum-mimimum);
  for(P p:v) cout<<p.first<<' '<<p.second<<endl;
  return 0;
}