#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define fi first
#define se second
#define INF 1000000009
#define lINF 1000000000000000009
using ll = long long;

int main(){
  int n;
  cin>>n;
  int ans=0;
  for(int i=1;i<(n+1)/2;i++)ans++;
  cout<<ans<<endl;
  return(0);
}
