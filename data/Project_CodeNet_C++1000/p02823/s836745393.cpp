#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;
using vs=vector<string>;

int main() {
  ll N,A,B; cin >>N >>A >>B;
  ll ans=0;
  if ((B-A)%2==0) {
    ans=(B-A)/2;
  } else {
    ans=min(A,N-B+1)+(B-A-1)/2;
  }
  cout <<ans <<endl;
  return 0;
}
