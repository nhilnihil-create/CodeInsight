#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;

bool IsPrime(ll num) {
  if (num==1) return false;
  if (num==2) return true;
  if (num%2==0) return false;
  int i=3;
  while (i<=sqrt(num)) {
    if (num%i==0) return false;
    i+=2;
  }
  return true;
}

int main() {
  int X; cin >>X;
  rep(i,X,pow(10,6)) {
    if (IsPrime(i)) {
      cout <<i <<endl;
      return 0;
    }
  }
}
