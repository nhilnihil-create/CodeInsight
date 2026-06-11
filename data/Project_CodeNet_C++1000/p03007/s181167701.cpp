#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <iomanip>

typedef long double ld;
typedef long long ll;

using namespace std;


#define MAXN (1 << 20)

vector<int> pos, neg;
int a[MAXN];
int n;
vector<pair<int, int> > ans;

int main() {
	cout << fixed << setprecision(12);	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] >= 0) {
			pos.push_back(a[i]);
		} else if (a[i] < 0) {
			neg.push_back(a[i]);
		} 
	}
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end(), greater<int>());
	if (pos.size() && neg.size()) {
		int nn = neg[0];
		int pp = pos[0];
		for (int i = 1; i < pos.size(); i++) {
			ans.push_back(make_pair(nn, pos[i]));
			nn -= pos[i];
		}
		for (int i = 1; i < neg.size(); i++) {
			ans.push_back(make_pair(pp, neg[i]));
			pp -= neg[i];
		}
		ans.push_back(make_pair(pp, nn));
	} else if (pos.size()) {
		int nn = pos[0];
		for (int i = 1; i < pos.size() - 1; i++) {
			ans.push_back(make_pair(nn, pos[i]));
			nn -= pos[i];
		}
		ans.push_back(make_pair(pos[pos.size() - 1], nn));
	} else if (neg.size()) {
		int nn = neg[0];
		for (int i = 1; i < neg.size(); i++) {
			ans.push_back(make_pair(nn, neg[i]));
			nn -= neg[i];
		}
	}
	pair<int, int> last = ans[ans.size() - 1];
	cout << last.first - last.second << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}
