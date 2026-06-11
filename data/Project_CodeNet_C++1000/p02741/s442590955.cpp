#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include <set>
#include <queue>
#include <climits>
#include <limits>
#include <map>
#include <unordered_map>
#include <cstring>
#include <ctime>

using namespace std;

#define ll long long
#define max(A, B) ((A) > (B) ? (A) : (B))
#define min(A, B) ((A) < (B) ? (A) : (B))
#define mp make_pair
#define pb push_back
#define fi first
#define sd second
#define fu(A, B, C) for(ll (A) = (B); (A) < (C); (A)++)
#define fu0(A, B) fu((A), 0, (B))
#define fd(A, B, C) for(ll (A) = (B); (A) >= (C); (A)--)
#define mem(A, B) memset((A), (B), sizeof((A)))
#define v(A, B, C) vector<ll> (A)((B), (C))
#define v2d(A, B, C) vector<vector<int>> (A)((B), vector<int> (C));
#define all(x) x.begin(), x.end()

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

void perform() {
  int arr[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  int k; cin >> k;
  cout << arr[k-1] << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t = 1; //cin >> t;
  while(t--) {perform();}
}
