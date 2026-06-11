#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> p(n);
	for(int& x : p) {
		cin >> x;
	}
	
	vector<int> left(n), right(n);
	stack<int> stk;
	for(int i = 0; i < n; i++) {
		while(stk.size() && p[i] > p[stk.top()]) {
			stk.pop();
		}
		
		left[i] = stk.empty() ? -1 : stk.top();
		stk.push(i);
	}
	
	stk = stack<int>();
	for(int i = n-1; i >= 0; i--) {
		while(stk.size() && p[i] > p[stk.top()]) {
			stk.pop();
		}
		
		right[i] = stk.empty() ? n : stk.top();
		stk.push(i);	
	}
	
	int B = 1;
	while(B < n) {
		B *= 2;
	}
	
	vector<int> tree(2*B);
	
	for(int i = 0; i < n; i++) {
		tree[i+B] = p[i];
	}
	
	for(int i = B-1; i > 0; i--) {
		tree[i] = max(tree[2*i], tree[2*i+1]);
	}
	
	auto get_max = [&](int L, int R) {
		L += B, R += B;
		int ans = 0;
		while(L <= R) {
			if(L % 2 == 1) ans = max(ans, tree[L++]);
			if(R % 2 == 0) ans = max(ans, tree[R--]);
			L /= 2, R /= 2;
		}
		return ans;
	};
	
	ll ans = 0;
	
	for(int i = 0; i < n; i++) {
		int L = left[i], R = right[i];
		if(L == -1 && R == -1) {
			continue;
		}
		
		//$ ll cur = 0;
		if(L != -1) {
			int lo = -1, hi = L-1;
			while(lo < hi) {
				int mid = lo + (hi-lo+1)/2;
				if(get_max(mid, L-1) > p[i]) {
					lo = mid;
				} else {
					hi = mid-1;
				}
			}
			
			ans += 1LL * p[i] * (L - lo) * (R - i);
			//$ cur += 1LL * p[i] * (L - lo) * (R - i);
		}
		
		if(R != n) {
			int lo = R+1, hi = n;
			while(lo < hi) {
				int mid = lo + (hi - lo)/2;
				if(get_max(R+1, mid) > p[i]) {
					hi = mid;
				} else {
					lo = mid + 1;
				}
			}
			
			ans += 1LL * p[i] * (hi - R) * (i - L);
			//$ cur += 1LL * p[i] * (hi - R) * (i - L);
		}
		
		//$ cerr << i << ' ' << cur << endl;
	}
	
	cout << ans << endl;
}
