#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main(){
  int n, m, ans=0;
  cin >> n >> m;
  vector<int> h(n);
  rep(i, n){
    cin >> h[i];
  }
  vector<int> a(m), b(m), c(n, 0), d(n, 0);
  rep(i, m){
    cin >> a[i] >> b[i];
  }

  rep(i, m){
    if(h[a[i]-1]>h[b[i]-1]){
      c[a[i]-1]++;
      c[b[i]-1]--;
      d[a[i]-1]++;
      d[b[i]-1]++;
    }
    if(h[b[i]-1]>h[a[i]-1]){
      c[a[i]-1]--;
      c[b[i]-1]++;
      d[a[i]-1]++;
      d[b[i]-1]++;
    }
    if(h[a[i]-1]==h[b[i]-1]){
      d[a[i]-1]+=100005;
      d[b[i]-1]+=100005;
    }
  }

  rep(i, n){
    if(c[i]==d[i]){
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}