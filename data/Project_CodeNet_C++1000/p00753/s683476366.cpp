#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cctype>

#define mp make_pair
#define pb push_back
#define REP(i,a,n) for(int i = a;i < (n);i++)
#define rep(i,n) for(int i = 0;i < (n);i++)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define range(x,min,max) ((min) <= (x) && (x) <= (max))

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef pair<int,int> PII;

const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};

vector<bool> isPrimes(int n) {
	vector<bool> res(n, true);
	res[0] = res[1] = false;
	for (int i = 2;i < sqrt(n);i++) {
		if (res[i]) {
			for (int j = 0;i * (j + 2) < n;j++) {
				res[i * (j + 2)] = false;
			}
		}
	}
	return res;
}

vector<int> primes(int n) {
	vector<bool> is_primes = isPrimes(n);
	vector<int> res;
	for (int i = 2;i < n;i++) {
		if (is_primes[i]) {
			res.push_back(i);
		}
	}
	return res;
}

int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	int n;
	VB ps = isPrimes(123456 * 2);
	while(1) {
		cin >> n;
		if (n == 0) break;
		int ans = [&] {
			int res = 0;
			REP (i, n + 1, (2 * n + 1)) {
				if (ps[i]) res++;
			}
			return res;
		}();
		cout << ans << endl;
	}
	return 0;
}