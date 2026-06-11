#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  sort(a.rbegin(),a.rend());
  int len = a[0]+1;
  vi cnt(len);
  for(int x : a) for(int i=x; i<=len; i+=x) cnt[i]++;
  int ans=0;
  for(int x : a){
    if(cnt[x] == 1) ans++;
  }
  cout << ans << endl;
}
