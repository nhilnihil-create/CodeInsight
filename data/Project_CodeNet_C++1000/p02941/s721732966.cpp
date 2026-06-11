#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
#define endl '\n'
using ll = long long;
#define int ll
using db = long double;
using ii = pair<int, int>;

const int N = 2e5 + 5, LG = 19, MOD = 998244353;
const int SQ =320;
const long double EPS = 1e-7;

int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

  int n;
  cin >> n;

  vector<ll>a(n),b(n);

  f(i,0,n)  cin >> a[i];
  f(i,0,n)  cin >> b[i];

  priority_queue<pair<ll,int>> pq;

  f(i,0,n)pq.emplace(b[i],i);

  ll ans = 0;
  while(pq.size()){

    int i;  ll val;
    tie(val,i)  = pq.top(); pq.pop();

    ll add = b[(i+1)%n] + b[(i+n-1)%n];
    ll mx = max({b[(i+1)%n],b[(i+n-1)%n],a[i]});

    ll diff = (add-1+val-mx) / add;
    ans += diff;
    val -= add * diff;
    b[i]= val;
    if(b[i] > a[i]){
      pq.emplace(b[i],i);
    }
    if(b[i] < a[i]) {
      cout << -1 << "\n"; return 0;
    }

  }

  cout<<ans<<'\n';




  return 0;
}
