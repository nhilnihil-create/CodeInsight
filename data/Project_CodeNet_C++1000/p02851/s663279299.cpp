#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, k;
  cin >> n >> k;
  vector < ll > a(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];
  ll ans = 0;
  vector < ll > p(n + 1, 0);
  queue < ll > q;
  map < ll, ll > mp;
  for(int i = 1; i < k && i <= n; i++){
    if(a[i] % k == 1) ans++;
    p[i] = p[i - 1] + a[i];
    ans += mp[(p[i] - i + k) % k];
    mp[(p[i - 1] - (i - 1) + k) % k]++;
    q.push((p[i - 1] - (i - 1) + k) % k);
  }

  for(int i = k; i <= n; i++){
    if(a[i] % k == 1) ans++;
    if(q.size() > 0){
      mp[q.front()]--;
      q.pop();
    }
    p[i] = p[i - 1] + a[i];
    ans += mp[(p[i] - i + k) % k];
    mp[(p[i - 1] - (i - 1) + k) % k]++;
    q.push((p[i - 1] - (i - 1) + k) % k);
  }

  cout << ans << endl;
}
