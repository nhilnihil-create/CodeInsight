#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll mod = 1000000007;
ll ans[100005];
ll L[100005];
ll R[100005];
int main() {
	string s;
	cin >> s;
	ll lcount = 0;
	ll rcount = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'L') {
			L[lcount] = i;
			lcount++;
		}
		else {
			R[rcount] = i;
			rcount++;
		}
		ans[i] = 0;
	}

	

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'R') {
			for (int j = 0; j <lcount; j++) {
				if (i < L[j]) {
					if ((L[j] - i) % 2 == 0) {
						ans[L[j]]++;
					}
					else {
					ans[L[j]-1]++;
					}
				break;
				}
			}
		}
		else {
			for (int k = rcount-1; k >= 0; k--) {
				if (i > R[k]) {
					if ((i - R[k]) % 2 == 0) {
						ans[R[k]]++;
					}
					else {
						ans[R[k]+1]++;
					}
					break;
				}
				
			}
		}
	}
	for (int i = 0; i < s.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}