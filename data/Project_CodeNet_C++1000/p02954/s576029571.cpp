#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}

int gyaku(int n){
    return modpow(n,MOD-2);
}
signed main() {
  int n;
  string s;
  cin>>s;
  n=s.size();
  vector<int>ans(n);
  int r=1,l=0,kyoukai=0;
  rep(i,n-1){
    if(s[i]=='R'&&s[i+1]=='R'){
      r++;
    }
    if(s[i]=='R'&&s[i+1]=='L'){
      l=1;
      kyoukai=i;
    }
    if(s[i]=='L'&&s[i+1]=='L'){
      l++;
    }
    if((s[i]=='L'&&s[i+1]=='R')||i==n-2){
      ans[kyoukai]=r-r/2+l/2;
      ans[kyoukai+1]=r+l-ans[kyoukai];
      r=1;
    }
  }
  rep(i,n){
    cout<<ans[i]<<' ';
  }
}
