#include<bits/stdc++.h>
#include<boost/dynamic_bitset.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main() {
	
	uint N;
	cin >> N;
	
	vector<vector<int>> P(N, vector<int>(N, -1));
	
	for(uint i=0; i<N; i++) {
		uint A;
		cin >> A;		
		for(uint j=0; j<A; j++) {
			int x, y;
			cin >> x >> y;
			P[i][x-1] = y;
		}
	}
	
	uint ans = 0;
	
	for(uint i=0; i<pow(2, N); i++) {
		boost::dynamic_bitset<> tf;
		tf.append(i);
		
        if(ans >= tf.count()) continue;

		bool judge = true;
		for(uint l=0; l<N && judge; l++) {
			if(tf[l]) {
				for(uint m=0; m<N && judge; m++) {
					if(P[l][m] == -1 || l == m) {
						continue;						
					} else if(P[l][m] != tf[m]) {
						judge = false;
					}
				}
			}
		}
		uint tans = tf.count();
		ans = (judge) ? max(ans, tans) : ans;
	}
		
	cout << ans << endl;
	return 0;
}
