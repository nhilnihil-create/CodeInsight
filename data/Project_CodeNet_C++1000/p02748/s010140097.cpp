#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)
 

int main(void) {
  int a,b,m;cin>>a>>b>>m;
  vector<int> A(a), B(b);
  fr(i,a) cin>>A[i];
  fr(i,b) cin>>B[i];
  int ans = 1e6;
  fr(i,m){
    int x,y,c;cin>>x>>y>>c;
    ans = min(ans, A[x-1] + B[y-1] - c);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  ans = min(ans, A[0]+B[0]);
  
 cout << ans << endl;
  return 0;
}