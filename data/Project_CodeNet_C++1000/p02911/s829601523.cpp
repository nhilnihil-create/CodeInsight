#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
ll Max = 10 + 1e12;
int N = 5 + 1e5;
int main()
{
	ll n, q, k;
	cin >> n >> k >> q;
	vector<int> aa(n, 0);
	vector<int> ter(n, q-k + 1); //耐えないといけない回数
	rep(i, min(k, q)) {
		int x;
		cin >> x;
		aa[x - 1]++;
	}
	rep(i, q - k) {
		int yy; cin >> yy;
		ter[yy - 1]--;
	}
	rep(i, n) {
		if (aa[i] >= ter[i])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}