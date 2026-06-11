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
	int n; cin >> n;
	vector<int> aa(n);
	rep(i, n) cin >> aa[i];
	vector<int> bb(n);
	bb = aa;
	sort(bb.rbegin(), bb.rend());
	rep(i, n) {
		if (aa[i] == bb[0]) cout << bb[1] << endl;
		else cout << bb[0] << endl;
	}
}