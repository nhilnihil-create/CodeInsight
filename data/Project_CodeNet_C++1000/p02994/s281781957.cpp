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
#define int long long
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
int a[maxn], b[maxn];
bool cmp(int i,int j){
	return b[i] < b[j];
}
int32_t main(){
	IOS;
	int n,l;
	cin >> n >> l;
	int mn = 1e9, val;
	int sum = 0;
	for(int i=0 ;i<n; i++){
		int x = l + i;
		if(abs(x) < mn)
			mn = abs(x), val = x;
		sum += x;
	}
	cout << sum - val << endl;
}
