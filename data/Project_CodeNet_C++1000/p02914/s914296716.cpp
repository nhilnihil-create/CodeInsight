#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int n; cin >> n; ll a[n], an1=0, an2=0, allxor=0;

  for(int i=0; i<n; i++) {
    cin >> a[i]; allxor ^= a[i];
  }
  
  /*
  for(int i=0; i<n; i++) {
    for(ll j=59; j>=0; j--) {
      printf("%d",(a[i]&(1ll<<j))>0);
    } printf("\n");
  }printf("\n");

  for(ll j=59; j>=0; j--) {
      printf("%d",(allxor&(1ll<<j))>0);
  } printf("\n\n"); */

  for(int i=0; i<n; i++) a[i] &= ~allxor;
  ll ans = 0, p=0, k=0;
  for(ll i=59; i>=0; i--) {
    for(k=p; k<n; k++) if (a[k]&(1ll<<i)) break;
    if (k==n) continue;
    //cout << "a"<<i;
    if (k!=p) a[p]^=a[k];
    for(ll l=p+1; l<n; l++) a[l]=min(a[l],a[l]^a[p]); p++;
  }

  /*
  for(int i=0; i<n; i++) {
    for(ll j=59; j>=0; j--) {
      printf("%d",(a[i]&(1ll<<j))>0);
    } printf("\n");
  }*/

  for(int i=0; i<n; i++) ans=max(ans,ans^a[i]);
  ans = ans * 2 + allxor;;
  cout<<ans<<endl;
  //cout << an1 + an2 << endl;
}