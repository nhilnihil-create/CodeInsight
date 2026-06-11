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
	int n;
	cin >> n;
	int mmax = 0;
	vector<string> as(n);
	map<string, int> mp;
	vector<string> ans(n);
	rep(i, n) {
		cin >> as[i];
		mp[as[i]]++;
		mmax = max(mmax, mp[as[i]]);
		
	}
	int aa = 0;
	rep(i, n) {
		if (mmax == mp[as[i]]) {
			ans[aa] = as[i];
			aa++;
			mp[as[i]] = 0;
		}
	}
	sort(ans.begin(), ans.begin()+aa);
	rep(i, aa) {
		cout << ans[i] << endl;
	}
}
