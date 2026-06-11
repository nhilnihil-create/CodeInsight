#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<ll>A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  vector<ll>c(N,0);
  ll ans=1;
  for(int i=0;i<N;i++){
    c[A[i]]++;
    if(A[i]==0)ans=(ans*(4-c[0]))%MOD;
    else ans=(ans*(c[A[i]-1]-c[A[i]]+1))%MOD;
  }
  cout<<(ans)%MOD<<endl;
  return 0;
}
