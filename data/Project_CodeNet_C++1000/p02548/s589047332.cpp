//#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii =  pair<int,int>;
const int  dir[2][2] = {{-1,0},{0,1}};
const int mod = 1000000007;
const int INF = 0x3f3f3f;
#define all(v) v.begin(),v.end()
ll quick_pow(ll base, ll n) {
    ll ans = 1;
    while (n ) {

        if (n & 1 )ans *= base;

        base *= base;
        n >>= 1;
    }
    return ans;

}
void solution();
int main() {
    int T = 1;
//    cin>>T;
    while (T--) {
        solution();
    }
    return 0;
}
void solution(){
  int n;
  scanf("%d",&n);
  --n;
  ll ans = 0;
  for(int i = 1; i <= (n); ++i) {
    ans += n/i;
  }
  cout<<ans<<endl;
}