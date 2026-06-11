#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <complex>
#include <vector>
#include<limits>
#include<iomanip>
#include<cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;

#define debug(x) cout << #x << " = " << (x) << endl;
#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n-1;i >= 0;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second

const long double pi = 3.141592653589793;
const int mod = 1e9 + 7;

ll N, u, v;
ll ans = 0;

int main() {

 // freopen("input.in","r",stdin);
 // freopen("output.out","w",stdout);

 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

 cin >> N;
 rep(i, N) ans += (i+1)*(N-i);
 rep(i, N-1) {
   cin>>u>>v;
   auto x = minmax(u, v);
   ans -= x.F * (N-x.S+1);
 }
 cout << ans <<endl;

 return 0;
}
