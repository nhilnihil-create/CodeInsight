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
const int mod = 1e9 + 7, base = 773;
inline int mu(int x,int y){
	return 1LL * x * y % mod;
}
inline int ad(int x,int y){
	return (x + y) % mod;
}
int h[maxn], pw[maxn], h2[maxn];
int gh(int l,int r){
	return ad(h[r], mod - mu(h[l], pw[r - l]));
}
int32_t main(){
	//IOS;
	int n;
	string s;
	cin >> s;
	bool can = 1;
	for(int i=0; i<s.size(); i++){
		if(i % 2 == 0 && s[i] == 'L')
			can = 0;
		if(i % 2 == 1 && s[i] == 'R')
			can = 0;
	}
	if(can)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
