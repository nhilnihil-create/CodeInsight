#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define wzh(x) cerr<<#x<<' '<<x<<endl
int main() {
  ios::sync_with_stdio(false);
  int n,x,ans=0;cin>>n;
  for(int i=1;i<=n;i++){
  	cin>>x;
  	if((i)&1 && (x&1)){
  		ans++;
  		// cout<<i<<' '<<x<<endl;
  	}
  }
  cout<<ans<<'\n';
 	return 0;
}