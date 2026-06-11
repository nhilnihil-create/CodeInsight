#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

  ll n, k, s; cin >> n >> k >> s;
  ll out = s+1;
  if(1'000'000'000<out) out = 1;
  for(int i=0; i<n; i++){
    ll p=s;;
    if(k<=i) p = out;
    cout << p << ' ';
  }
  cout << endl;
}
