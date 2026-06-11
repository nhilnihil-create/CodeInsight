#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define FOR(var,start,end) for(int var=start; var<end; var++)
#define REP(var,cnt) FOR(var,0,cnt)

pair<int, int> pd[10010];

int main(void) {
	while(true) {
		int N, M;
		cin >> N >> M;
		if ( N==0 ) { break; }
		
		
		REP(i, N) {
			int D, P;
			cin >> D >> P;
			pd[i] = make_pair(P,D);
		}
		sort(pd, pd+N);
		reverse(pd, pd+N);
		
		int ret = 0;
		REP(i, N) {
			if ( M > 0 ) {
				M -= pd[i].second;
				if ( M < 0 ) {
					ret += -M * pd[i].first;
				}
			} else {
				ret += pd[i].first*pd[i].second;
			}
		}
		
		cout << ret <<endl;
	}
}