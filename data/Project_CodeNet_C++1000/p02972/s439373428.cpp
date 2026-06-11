#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi a(n+1), ans(n+1);
  rep(i,n) cin >> a[i+1];
  for(int i = n; i > 0; i--){
    int cnt = 0;
    for(int j = i; j <= n; j+=i){
      if(ans[j] == 1) cnt++;
    }
    if((cnt + a[i])%2 == 0) continue;
    else ans[i]++;
  }
  int m = 0;
  rep(i,n){
    if(ans[i+1] == 1) m++;
  }
  cout << m << endl;
  rep(i,n){
    if(ans[i+1] == 1) cout << i+1 << " ";
  }
}
