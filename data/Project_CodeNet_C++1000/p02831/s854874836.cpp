#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;

ll gcd(ll a,ll b) {
  if (a%b==0) {
    return b;
  } else {
    return gcd(b,a%b);
  }
}

ll lcm(ll a,ll b) {
  return a*b/gcd(a,b);
}

int main() {
  ll A,B; cin >>A >>B;
  cout <<lcm(A,B) <<endl;
  return 0;
}
