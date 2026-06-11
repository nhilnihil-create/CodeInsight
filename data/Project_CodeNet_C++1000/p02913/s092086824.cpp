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
const int mod = 1e9 + 7;
const int base[] = {4001, 4001};
inline int mu(int x,int y){
	return 1LL * x * y % mod;
}
inline int ad(int x,int y){
	return (x + y) % mod;
}
int h[2][maxn], pw[2][maxn];
int gh(int l,int r, int k){
	return ad(h[k][r], mod - mu(h[k][l], pw[k][r - l]));
}
pii gh2(int l,int r){
	return {gh(l, r, 0), gh(l, r, 1)};
}
int32_t main(){
	//IOS;
	int n; string s;
	cin >> n >> s;
	for(int i=0; i<2; i++){
		pw[i][0] = 1;
		for(int j=1; j<maxn; j++)
			pw[i][j] = mu(pw[i][j - 1], base[i]);
		for(int j=1; j<=n; j++)
			h[i][j] = ad(mu(h[i][j - 1], base[i]), s[j - 1] + 33);
	}
	int lo = 0, hi = n;
	while(hi - lo > 1){
		int mid = hi + lo >> 1;
		map<pii,bool> mp;
		bool can = 0;
		for(int r=n; r-mid>=0; r--){
			mp[gh2(r - mid, r)] = 1;
			if(r >= 2* mid){
				auto val = gh2(r - 2 * mid, r - mid);
				if(mp[val])
					can = 1;
			}
		}
		if(can)
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << endl;
}
