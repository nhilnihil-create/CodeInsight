#include <bits/stdc++.h>
using namespace std;

int64_t mod=998244353;

int64_t jo(int64_t a,int64_t b){
  int64_t c=a;
  for(int i=0; i<b-1; i++){
    c = c*a;
    c = c%mod;
  }
  if (b==0) c=1;
  return c;
}

int main(){
  int n;
  cin >> n;
  int64_t ans=1;
  vector<int64_t> cnt(n);
  for(int i=0; i<n; i++){
    int64_t x;
    cin >> x;
    cnt.at(x)++;
    if (x==0&&i!=0) ans=0;
    if (x!=0&&i==0) ans=0;
  }
  for(int i=0; i<n-1; i++){
    ans = ans*jo(cnt[i],cnt[i+1]);
    ans = ans%mod;
  }

  cout << ans << endl;
}