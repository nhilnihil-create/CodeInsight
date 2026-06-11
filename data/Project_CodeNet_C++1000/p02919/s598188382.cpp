#include "bits/stdc++.h"
using namespace std;
int main() {
	int N;
	cin >> N;
	map<int,int>mp;
	for (int n = 0;n<N;++n) {
		int num;
		cin >> num;
		mp[num] = n;
	}
	set<int>S; 
	S.insert(-1); 
	S.insert(N);
	long long ans = 0;
	for (int n = N; n > 0; --n) {
		int num = mp[n];
		S.insert(num);
		set<int>::iterator it = S.find(num);
		int l1, l2;
		int r1, r2;
		{
			it--;
			l2 = *it;
			if (-1 != *it) {
				it--;
			}
			l1 = *it;
		}
		{
			it = S.find(num);
			it++;
			r1 = *it;
			if (N != *it) {
				it++;
			}
			r2 = *it;
		}
		ans += (long long)n*(r2 - r1)*(num-l2);
		ans += (long long)n*(l2 - l1)*(r1-num);
	}
	cout << ans <<endl;
	return 0;
}