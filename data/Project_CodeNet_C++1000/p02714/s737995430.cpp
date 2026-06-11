#include<bits/stdc++.h>
using namespace std;

long long N;
string S;
set<long long> R;
set<long long> G;
set<long long> B;

int main(){
	cin >> N >> S;

	for(long long i = 0; i < N; i++) {
		if(S[i] == 'R') {
			R.insert(i);
		} else if (S[i] == 'G') {
			G.insert(i);
		} else {
			B.insert(i);
		}
	}


	long long ans = 0;
	for(auto ridx: R) {
		for(auto gidx: G) {
			ans += B.size();
			// r, g, b
			if(ridx < gidx) {
				long long bidx = gidx + (gidx - ridx);
				if(B.count(bidx)>0) {
					ans--;
				}
			}
			// r, b, g
			if(ridx + 1 < gidx) {
				if((gidx - ridx)%2 == 0) {
					long long bidx = ridx + (gidx - ridx)/2;
					if(B.count(bidx)>0) {
						ans--;
					}
				}
			}

			// g, r, b
			if(gidx < ridx) {
				long long bidx = ridx + (ridx - gidx);
				if(B.count(bidx)>0) {
					ans--;
				}
			}

			// g, b, r
			if(gidx + 1 < ridx) {
				if((ridx - gidx)%2 == 0) {
					long long bidx = gidx + (ridx - gidx)/2;
					if(B.count(bidx)>0) {
						ans--;
					}
				}
			}

			// b, g, r
			if(gidx < ridx) {
				long long bidx = gidx - (ridx - gidx);
				if(B.count(bidx)>0) {
					ans--;
				}
			}

			// b, r, g
			if(ridx < gidx) {
				long long bidx = ridx - (gidx - ridx);
				if(B.count(bidx)>0) {
					ans--;
				}
			}
		}
	}
	cout << ans << endl;
}
