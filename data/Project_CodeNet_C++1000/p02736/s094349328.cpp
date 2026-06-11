// Sky's the limit :)
#include<bits/stdc++.h>
using namespace std;
#define int long long

int lucas(int n, int r) {
	for(int i = 0; i < 20; i++) {
		if(!(n & (1 << i)) && (r & (1 << i)))
			return 0;
	}
	return 1;
}

int odd_ans(vector<int> v) {
	int n = v.size(), ans = 0;
	for(int i = 0; i < n; i++) {
		if(v[i] % 2 && lucas(n - 1, i)) {
			ans ^= 1;
		}
	}
	return ans;
}

// https://atcoder.jp/contests/agc043/tasks/agc043_b
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	//int t = 1; cin >> t; while(t--)
	{
		int n;
		string s;
		cin >> n >> s;

		vector<int> a(n);
		for(int i = 0; i < n; i++)
			a[i] = s[i] - '0';

		vector<int> b;
		for(int i = 0; i < (int)a.size() - 1; i++) {
			b.push_back(abs(a[i] - a[i + 1]));
		}
		a = b;
		n--;

		if(n == 1)
			return cout << a[0], 0;

		int ans = 0;
		if(odd_ans(b)) 
			return cout << "1\n", 0;
		
		for(auto& x : b) {
			if(x == 1)
				return cout << "0\n", 0;
			x /= 2;
		}

		if(odd_ans(b))
			cout << "2\n";
		else
			cout << "0\n";
	}
	
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}

