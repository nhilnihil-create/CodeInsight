#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>
using namespace std;
//#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
#define X first
#define Y second
#define all(o) o.begin(), o.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0), cin.tie(0)

int gcd(int x,int y){ return (!y ? x : gcd(y, x%y)); }
const int maxn = 1e6 + 10;
vi adj[maxn];
void ad_e(int u,int v){
	adj[u].push_back(v);
}
int32_t main(){
	IOS;
	int n;
	cin >> n;
	if(__builtin_popcount(n) == 1){
		cout << "No\n";
		return 0;
	}
	int m = (n % 2 == 0 ? n - 1 : n);
	int st = 1;
	ad_e(1+n, 2+n), ad_e(2+n, 3), ad_e(3, 1);
	ad_e(1, 2), ad_e(2, 3+n);
	
	for(int i=4; i<=m; i++){
		ad_e(st, i);
		ad_e(i, (i^1) + n);
	}
	if(m != n){
		for(int u=2; u<=m; u++){
			int v = n ^ 1 ^ u;
			if(v != u && v <= m){
				ad_e(v, n);
				ad_e(u, 2*n);
				break;
			}
		}
	}
	cout << "Yes\n";
	for(int i=1; i<=2*n; i++)
		for(auto j : adj[i]){
			cout << i << " " << j << endl;
		}
}
