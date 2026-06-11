#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma comment(linker, "/STACK:2000000")

#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
// #define endl '\n'
using ll = long long;
using db = long double;
using ii = pair<int, int>;

const int N = 2e5+5, LG = 19, MOD = 998244353;
const int SQ =320;
const long double EPS = 1e-7;
int n, m;

int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

  int n;
  cin >> n;

  if(!(n&(n-1))){
    ///power of two
    cout << "No\n";
  } else {
    cout << "Yes\n";

    cout << "1 2\n";
    cout << "2 3\n";
    cout << n + 1 << ' ' << n + 2 <<'\n';
    cout << n + 3 << ' ' << n + 2 <<'\n';
    cout << 3 <<  " " << n + 1 << '\n';
    for(int i = 4; i < n; i += 2){
      cout<< i << ' ' << i + 1 << '\n';
      cout<< n+i << ' ' << n+i + 1 << '\n';
      cout<<  1 << ' ' << i << '\n';
      cout<<  1 << ' ' << n+i+1 << '\n';
    }

    if(n&1^1){
      int lft = n-(n&-n);
      cout << n << ' ' << (lft+1+n) << '\n';
      cout << n+n<<' '<< (n&-n) << '\n';
    }

  }

  return 0;
}
