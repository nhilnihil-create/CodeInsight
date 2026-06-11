#include <math.h>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	while(true) {
		int n;
		cin >> n;
		int m;
		cin >> m;
		if ( n == 0 ) break;
		int k;
		vector<int> roadh;
		vector<int> listh;
		for ( int i = 0; i < n; i++ ) {
			cin >> k;
			roadh.push_back(k);
			k = 0;
			for ( int j = i; j >= 0; j-- ) {
				k += roadh[j];
				listh.push_back( k );
			}
		}
		vector<int> roadw;
		vector<int> listw;
		for ( int i = 0; i < m; i++ ) {
			cin >> k;
			roadw.push_back(k);
			k = 0;
			for ( int j = i; j >= 0; j-- ) {
				k += roadw[j];
				listw.push_back( k );
			}
		}
		sort( listh.begin(), listh.end() );
		sort( listw.begin(), listw.end() );
		int start = 0;
		int sum = 0;
		int cnt = 0;
		for ( int i = 0; i < listh.size() ; i++ ) {
			if ( i != 0 ) {
				if ( listh[i] == listh[i-1] ) {
					sum += cnt;
					continue;
				}
			}
			cnt = 0;
			for ( int j = start; j < listw.size(); j++ ) {
				if ( listh[i] == listw[j] ) {
					cnt++;
				}else if ( listh[i] < listw[j] ) {
					start = j;
					break;
				}
			}
			sum += cnt;
		}
		cout << sum << endl;
	}
	return 0;
}