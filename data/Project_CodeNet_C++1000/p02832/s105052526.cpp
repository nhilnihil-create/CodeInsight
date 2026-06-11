#include <bits/stdc++.h>

using namespace std;

#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define f first
#define s second

#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << endl;}

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const ll inf = 1e12;
const ll mod = 1e9 + 7;


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll n; cin >> n;

  ll arr[n];
  
  f0r(i, n) {
    cin >> arr[i];
  }

  ll ret = 0;

  f0r(i, n) {
    if (i - ret + 1 != arr[i]) {
      ret++;
    } 

  }

  if (ret == n) {
    ret = -1;
  }

  cout << ret << endl;

}