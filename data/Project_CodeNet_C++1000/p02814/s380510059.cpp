#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

ll gcd(ll a, ll b) {
  ll v0=a, v1=b, v2=v0%v1;
  while(v2>0) {
    v0 = v1;
    v1 = v2;
    v2 = v0%v1;
  }
  return v1;
}

ll lcm(ll a, ll b) {
  return a*b/gcd(a, b);
}

int main() {
  ll N, M;
  cin>>N>>M;
  vector<ll> A(N), B(N);
  for(int i=0;i<N;++i) cin>>A[i];
  sort(A.begin(), A.end());
  for(int i=0;i<N;++i) B[i] = A[i]/2;
  ll tmp;
  if(N==1) tmp = B[0];
  else tmp = lcm(B[0], B[1]);
  for(int i=2;i<N;++i) tmp = lcm(tmp, B[i]);
  bool can = true;
  for(int i=0;i<N;++i) {
    if(tmp/B[i]%2==0) can = false;
  }
  if(tmp>M || !can) cout<<0<<endl;
  else cout<<1+(M-tmp)/(2*tmp)<<endl;
}

