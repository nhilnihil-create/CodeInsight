#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define fi first
#define se second
#define INF 1000000009
#define LLINF 1000000000000000009LL
using ll = long long;

int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  int j=n-1;
  int ans=0;
  rep(i,n){
    if(s[i]=='W'){
      while(s[j]=='W'){
        j--;
      }
      if(i>=j)break;
      swap(s[i],s[j]);
      ans++;
    }
  }
  cout<<ans<<endl;
  return(0);
}