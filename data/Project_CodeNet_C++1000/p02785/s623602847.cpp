/****************************************

	LostMartian

****************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
using namespace std;
typedef long long ll;
#define rep(i,m,n) for(ll i=m; i<n; i++)
#define repr(i,m,n) for(ll i=m; i>=n; i--)
#define vll vector<ll >
#define vvl vector<vector<ll > >
#define pi pair<ll, ll >
#define pb push_back
#define mk make_pair
#define sz size()
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define d(x) cout<<"Value of "#x" = "<<x<<"\n";
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define LOCAL #ifndef ONLINE_JUDGE freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); #endif
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
int main()
{
	clock_t z = clock();
	FAST
	//LOCAL
	ll n, k;
	cin>>n>>k;
	ll a[n];
	ll s=0;
	rep(i,0,n) {
		cin>>a[i];
	}
	ll sum=0;
	sort(a, a+n);
	rep(i,0,n-k) {
		sum+=a[i];
	}
	cout<<sum<<"\n";
	

	debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
	return 0;
}
