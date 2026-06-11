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
ll Max = 10 + 1e8;
int main()
{
	int n;
	cin >> n;
	vector<string> s(n);
	int Maax = 0;
	map<string, int> mp;
	rep(i, n) {
		cin >> s[i];
		mp[s[i]]++;
		Maax = max(mp[s[i]], Maax);
	}
	vector<string>ss(n);
	int cnt = 0;
	rep(i, n) {
		if (mp[s[i]] == Maax) {
			ss[cnt] = s[i];
			mp[s[i]] = 0;
			cnt++;
		}
	}
	sort(ss.begin(), ss.begin() + cnt);
	rep(i, cnt)
		cout << ss[i] << endl;
}
