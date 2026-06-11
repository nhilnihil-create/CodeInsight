#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

const int maxn = 1e6 + 5;

int n, k;
ll a[maxn], acc[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

  cin>>n>>k;
  for (int i=1; i<=n; i++) {
    cin>>a[i];
    acc[i]=a[i]+acc[i-1];
  }

  ll ans = 0;
  map<ll,int> cnt;

  cnt[0] = 1;
  for (int i=1; i<=n; i++) {
    if (i-k>=0) {
      ll v = (acc[i-k]-(i-k))%k;
      v = (v+k)%k;
      cnt[v]--;
    }
    ll v = (acc[i]-i+k)%k;
    v = (v+k)%k;    
    ans += cnt[v];
    cnt[v]++;
  }

  
  cout<<ans<<endl;
  return 0;
}
