#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define fi first
#define se second
#define pf push_front
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define debug(x) cerr<<#x<<": "<<(x)<<'\n'
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll nax = 0;

int main(){
  IOS
  int ans=0, x;
  cin >> x;
  int ba=0;
  while(1){
    if((ba%360==0) && ans>0){
      break;
    }
    ans++;
    ba=(ba+x)%360;
  }
  cout << ans << '\n';
}
