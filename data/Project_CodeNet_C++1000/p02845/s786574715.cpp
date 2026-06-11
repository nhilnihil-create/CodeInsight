#include <bits//stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main() {
	int n;cin >> n;
  vector<int> a(n),c(3,0);
  rep(i,n) cin >> a[i];
  ll ans = 1;
  rep(i,n){
    ll cnt = 0,id = -1;
    if(a[i]==c[0]){cnt++;id=0;}
    if(a[i]==c[1]){cnt++;id=1;}
    if(a[i]==c[2]){cnt++;id=2;}
    if(id==-1){
      cout << 0<<endl;
      return 0;
    }ans *= cnt;ans %=1000000007;c[id]++;
  }cout << ans << endl;
}