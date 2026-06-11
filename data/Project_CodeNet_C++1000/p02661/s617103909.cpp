#include <bits/stdc++.h> 

#define int ll

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 998244353
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<int>A(N),B(N);
  for(int i=0;i<N;i++)cin>>A[i]>>B[i];
  sort(rng(A));
  sort(rng(B));
  if(N%2)cout<<B[N/2]-A[N/2]+1<<endl;
  else cout<<(B[N/2-1]+B[N/2])-(A[N/2-1]+A[N/2])+1<<endl;

  return 0;
}
