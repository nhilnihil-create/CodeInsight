#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
#define all(v) v.begin(), v.end()

int main(){
  ll S;
  cin >> S;
  cout << 0 << " " << 0 << " " << 1000000000 << " " << 1 << " ";
  cout << 1000000000-(S-1)%1000000000-1 << " " << (S-1)/1000000000+1 << endl;
  
}

