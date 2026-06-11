#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;

#define mod (1e9 + 7)
#define PI 3.1415926535897932
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<int, int>
#define fi first
#define se second

typedef long long ll;

ll comb(ll n) {
   return n*(n-1)/2;
}

void solve1()
{
   int n; cin >> n;
   set<int> s;
   vector<int> a(n); 
   rep(i, n) {
      cin >> a[i];
      s.insert(a[i]);
   }

   vector<int> as(a);
   map<int, int> m;
   sort(all(as));

   ll sum = 0;
   for(set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
      int num = upper_bound(all(as), *itr) - lower_bound(all(as), *itr);
      m.insert(make_pair(*itr, num));
      sum += comb(m[*itr]);
   }

   rep(i, n) {
      cout << sum - comb(m[a[i]]) + comb(m[a[i]]-1) << endl;
   }

}

int main()
{
   solve1();
}
