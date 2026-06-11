#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <assert.h>
#include <cmath>
#include <deque>
#include <set>
#include <unordered_map>
#include <complex>
#include <fstream>
using namespace std;
using ll = long long;
using ld = long double;
const int mxn = 20;
int s[1<<mxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>>n;

	for(int i=0; i<(1<<n); i++) cin>>s[i];

	multiset<int, greater<int> > set;

	sort(s, s+(1<<n), greater<int>());

	for(int i=1; i<(1<<n); i++) set.insert(s[i]);
	//for(auto it = set.begin(); it!=set.end(); it++) cout << *it << " ";
	//cout << '\n';

	vector<int> tmp;
	tmp.push_back(s[0]);
	//set.erase(set.begin());

	while((1<<n)!=(int)tmp.size()) {
		vector<int> tmp2;
		for(auto x:tmp) {
			auto it = set.upper_bound(x);
			//if(it!=set.end()) cout << *it << " ";
			//cout << "ds" <<x;
			//cout << '\n';
			if(it==set.end()) {
				cout << "No\n";
				return 0;
			}
			else tmp2.push_back(*it), set.erase(it);
		}
		tmp.insert(tmp.end(), tmp2.begin(), tmp2.end());
		//sort(tmp.begin(), tmp.end(), greater<int> ());
	}
	cout << "Yes\n";
	return 0;
}