#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9+7;
typedef long long int lli;
typedef pair<lli,lli> pii;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<bool> vb;
long long int max(long long int a,long long int b){
  if(a>b)
    return a;
  else
    return b;
}
long long int binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
      a = a * a % m;
      b >>= 1;
    }
  return res;
}
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

//############################ENDOFTEMPLATE############################



void solve(){
  lli n,k;
  cin>>n>>k;

  vlli a(n);
  for(int i = 0;i<n;i++){
    cin>>a[i];
  }

  
  lli cnt1 = 0;
  for(int i = 0;i<n;i++){
    
    for(int j = i+1;j<n;j++){
      if(a[j]<a[i])
        cnt1++;
    }

    
  }

  lli cnt2 = 0;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      if(a[j]<a[i])
        cnt2++;
    }
  }

  

  long long ans = 0;
  lli m1 = (k*(k-1)/2)%mod;
  lli m2 = k%mod;

  ans = (cnt1*m2+cnt2*m1)%mod;

  cout<<ans;


}



int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  //freopen("input_custom.txt","w",stdout);
  int t = 1;
  //cin>>t;
  while(t--){
    solve();
  }
}