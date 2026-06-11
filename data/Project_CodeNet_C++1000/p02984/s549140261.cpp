#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
#define wzh(x) cerr<<#x<<'='<<x<<endl;
int n,a[N];
LL ans[N];
int main() {
  ios::sync_with_stdio(false);
  cin>>n;LL s=0;
  for(int i=1;i<=n;i++) {
    cin >> a[i];
    s+=(i&1?1:-1)*a[i];
  }
  ans[1]=s;
  for(int i=2;i<=n;i++){
    ans[i]=(2*a[i-1]-ans[i-1]);
  }
  for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
  return 0;
}