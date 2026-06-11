#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  long n,k;
  cin >> n >> k;
  long mod = INF;
  long ans = 0;
  for(long ki=k;ki<=n+1;ki++){
    ans += n*(n+1)/2 - (n-ki)*(n-ki+1)/2 - ki*(ki-1)/2 + 1;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}