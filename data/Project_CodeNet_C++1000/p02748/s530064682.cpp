#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int A,B,M; cin >>A >>B >>M;
  vector<int> a(A);
  rep(i,0,A) {cin >>a[i];}
  vector<int> b(B);
  rep(i,0,B) {cin >>b[i];}
  int ans=*min_element(a.begin(),a.end())+*min_element(b.begin(),b.end());
  rep(i,0,M) {
    int x,y,c; cin >>x >>y >>c;
    int temp=a[x-1]+b[y-1]-c;
    ans=min(ans,temp);
  }
  cout <<ans <<endl;
  return 0;
}
