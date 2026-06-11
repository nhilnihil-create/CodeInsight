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
  sort(a.begin(),a.end());
  int len = a[n-1]+1;
  vi yakusuu(len);
  rep(i,n){
    for(int j=a[i]; j<=len; j+=a[i]){
      yakusuu[j]++;
    }
  }
  int ans=0;
  rep(i,n){
    if(yakusuu[a[i]] == 1) ans++;
  }
  cout << ans << endl;
}
