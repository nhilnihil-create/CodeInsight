#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int main()
{
  int N;
  cin >> N;
  vector<ll>A(N),B(N),C(N);
  ll ans=0;
  rep(i,N)cin >> A[i];
  rep(i,N){cin >> B[i];ans+=B[i];}
  rep(i,N-1)cin >> C[i];
  rep(i,N-1){
    if(A[i]+1==A[i+1])ans+=C[A[i]-1];
  }
  cout << ans << endl;
  return 0;
}