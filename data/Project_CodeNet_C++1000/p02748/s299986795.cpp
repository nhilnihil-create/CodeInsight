#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep1(i,n) for(long long i=1;i<=(long long)(n);i++)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main() {
  ll A,B,M,Min=3*100000;
  cin>>A>>B>>M;
  vector<ll> a(A),b(B);
  rep0(i,A){cin>>a[i];}
  rep0(i,B){cin>>b[i];}
  vector<vector<ll>> dsc(M,vector<ll>(3));
  rep0(i,M){rep0(j,3){cin>>dsc[i][j];}}
  rep0(i,M){Min=min(Min,a[dsc[i][0]-1]+b[dsc[i][1]-1]-dsc[i][2]);}
  sort(all(a));
  sort(all(b));
  Min=min(Min,a[0]+b[0]);
  cout<<Min<<endl;
}
