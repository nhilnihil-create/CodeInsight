#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;
ll d[100100];
int main(void){
  ll n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>d[i];
  sort(d,d+n);
  cout<<d[n/2]-d[n/2-1]<<endl;
}