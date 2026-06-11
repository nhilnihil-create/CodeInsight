#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	//[R...L]の部分文字列について解決すればいい
	//r=1,l=1のとき、(1,1)
	//r=偶数,l=偶数のとき、(0がr-1個,r/2+l\2,r/2+l/2,0がl-1個)
	//rが奇数,lが奇数の時、(0がr-1個,ceil(r/2)+l\2,r/2+ceil(l/2),0がl-1個)
	vector<vector<int>>a(0, vector<int>(2));
	int rc = 0;
	int lc = 0;
	for (size_t i = 0; i < s.length(); i++) {
		if (lc==0 && s.at(i) == 'R') rc++;
		else if (rc >= 1 && s.at(i) == 'L') lc++;
		else if (rc >= 1 && lc >= 1 && s.at(i) == 'R') {
			a.push_back({ rc,lc });
			rc = 1;
			lc = 0;
		}
	}
	a.push_back({ rc,lc });
	//for (size_t i = 0; i < a.size(); i++)cout << a.at(i).at(0) << " " << a.at(i).at(1) << endl;
	vector<int>ans;
	for (size_t i = 0; i < a.size(); i++) {
		int rx = a.at(i).at(0);
		int lx = a.at(i).at(1);
		for (size_t j = 0; j < rx - 1; j++) ans.push_back(0);
		ans.push_back(ceil(rx * 0.5) + (lx / 2));
		ans.push_back(ceil(lx * 0.5) + (rx / 2));
		for (size_t j = 0; j < lx - 1; j++)ans.push_back(0);
	}
	cout << ans.at(0);
	for (size_t i = 1; i < ans.size(); i++)cout << " " << ans.at(i);
	cout << endl;
}