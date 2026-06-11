#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> a(n+1); rep(i,n+1) cin >> a[i];
  vector<int> b(n); rep(i,n) cin >> b[i];

  ll ans = 0;
  if(b[0]>=a[0]){
    ans+=a[0];
    b[0]-=a[0];
    a[0]=0;
  }
  else{
    ans+=b[0];
    b[0]=0;
  }
  
  for(int i = 1;i<n;i++){
    if(a[i]<=b[i-1]){
      ans += a[i];
      b[i-1] -= a[i];
      a[i]=0;
    }
    else{
      ans+=b[i-1];
      a[i] -= b[i-1];
      b[i-1] = 0;
    }
    if(a[i]<=b[i]){
      ans+=a[i];
      b[i] -= a[i];
      a[i]=0;
    }
    else{
      ans+=b[i];
      a[i] -= b[i];
      b[i] = 0;
    }
  }
  if(a[n]<=b[n-1]){
    ans+=a[n];
    b[n-1] -= a[n];
    a[n] = 0;
  }
  else{
    ans+=b[n-1];
    a[n]-=b[n-1];
    b[n-1]=0;
  }
  
  /*cout << "a" << endl;
  rep(i,n+1){
    cout << a[i] << " ";
  }
  cout << endl << "b" << endl;
  rep(i,n){
    cout << b[i] << " ";
  }
  cout << endl;
  */
  cout << ans << endl;
  
  return 0;
}
