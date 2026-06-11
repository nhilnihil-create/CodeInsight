#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)

using namespace std;

int main(void) {	
	int n, k;
	while (cin >> n >> k && (n > 0 || k > 0)) {
		int ans = 0;
		FOR(i, 1, n - 2) {
			FOR(j, i + 1, n - 1) {
				FOR(l, j + 1, n) {
					if (i + j + l == k) {
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
		
	}
	
				  
	return 0;
}