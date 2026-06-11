#include<bits/stdc++.h>
#include<boost/dynamic_bitset.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main() {
	string S;
	cin >> S;

	u64 mod = 2019;
	u64 ans = 0;
	vector<bool> search_done(S.size()+1);
	
	for(u64 b=0; b<S.size(); b++) {
		if(search_done[b]) continue;

		u64 tmp_div = 0;
		u64 num_b_variations = 0;
		
		for(u64 e=b; e<S.size(); e++) {
			tmp_div = tmp_div * 10 + S[e] - '0';
			bool is_zero = (tmp_div == 0);
			if(is_zero && search_done[e]) break;

			tmp_div = tmp_div % mod;
			if(!is_zero && tmp_div == 0) {
				num_b_variations++;
				ans += num_b_variations;
				search_done[e+1] = true;
			}
		}
	}

	cout << ans << endl;
}
