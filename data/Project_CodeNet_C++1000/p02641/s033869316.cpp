#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;
ll mod(ll x) {
	return (x%MOD + MOD) %MOD;
}
ll mul(ll a,ll b) {
	return mod(mod(a) * mod(b));
}

int main() {
	int x,n;
	cin >> x >> n;
	unordered_map<int,int> hash;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		int tmp;
		cin >> tmp;
		hash[tmp]++;
	}
	int left = x;
	int right = x;
	while(left >= 0) {
		if(hash.find(left) == hash.end())
			break;
		left--;
	}
	while(right <= 101) {
		if(hash.find(right) == hash.end())
			break;
		right++;
	}

	int result = ((x-left) > (right-x))?right:left;
	cout << result << endl;
}