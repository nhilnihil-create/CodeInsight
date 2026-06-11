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
ll a[200005];

int main() {
	ll n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int>s;
	vector<int>ord(n + 1, -1);
	int c = 1,l = 0;
	
	{
		int v = 1;
		
		while (ord[v] == -1) {
			ord[v] = s.size();
			s.push_back(v);
			v = a[v - 1];
		}
		c = s.size() - ord[v];
		l = ord[v];
	}
	if (k < l) {
		cout << s[k] << endl;
	}
	else {
		k -= l;
		k %= c;
		cout << s[l + k] << endl;
	}
	return 0;
}