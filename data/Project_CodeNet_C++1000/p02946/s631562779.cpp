#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  ll k, x; cin>>k>>x;
  ll upper=x+k-1;
  ll lower=x-k+1;
  
  for(ll i=lower; i<=upper; i++) cout << i <<" ";
}