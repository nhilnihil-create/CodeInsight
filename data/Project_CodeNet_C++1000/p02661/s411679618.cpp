#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
#define rep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

int main(){
  int n;
  cin >> n;
  vi a(n), b(n);
  rep(i, 0, n)
    cin >> a[i] >> b[i];
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  
  int ans;
  
  if(n%2 == 1){
    ll am, bm;
    am = a[(n-1)/2];
    bm = b[(n-1)/2];
    ans = bm - am +1;
  }
  else{
    ll am, bm;
    am = (a[n/2-1]+a[n/2]);
    bm = (b[n/2-1]+b[n/2]);
    ans = bm - am +1;
  }
  
  cout << ans << endl;
  
  return 0;
}