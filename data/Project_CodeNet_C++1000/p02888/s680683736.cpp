#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi l(n);
  rep(i,n) cin >> l[i];
  sort(l.begin(),l.end());
  ll ans = 0;
  for(int a=0; a<n-2; a++){
    for(int b=a+1; b<n-1; b++){
      for(int c=b+1; l[c]<l[a]+l[b]; c++){
        if(l[a] >= l[b] + l[c]) continue;
        if(l[b] >= l[a] + l[c]) continue;
        if(l[c] >= l[a] + l[b]) continue;
        ans ++;
      }
    }
  }
  cout << ans << endl;
}
