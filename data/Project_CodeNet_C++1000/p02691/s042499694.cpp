#include <bits/stdc++.h>
#include <boost/dynamic_bitset.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main() {
	s64 N;
	cin >> N;
	
	map<s64, u64> A1;
	map<s64, u64> A2;
	
	for(s64 i=0; i<N; i++) {
		s64 A;
		cin >> A;
		A1[i + A]++;
		A2[i - A]++;
	}
	
	u64 ans = 0;
	for(const auto& a : A1) {
		ans += A2[a.first] * a.second; 
	}
	
	cout << ans;
	
	return 0;
}
