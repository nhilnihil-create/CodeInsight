#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000
#define N 100000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  vector<ll> num(N+1, 0);
  ll sum = 0;
  for (int i = 0; i < n; i++){
    cin >> a[i];

    num[a[i]]++;
    sum += a[i];
  }
  ll q;
  cin >> q;
  
  for (ll i = 0; i < q; i++){
    ll b, c;
    cin >> b >> c;
    
    sum += (c - b)*num[b];
    num[c] += num[b];
    num[b] = 0;
    cout << sum << endl;
  }

  return 0;
}
