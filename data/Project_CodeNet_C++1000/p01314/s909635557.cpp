#include<iostream>
using namespace std;

int main() {
	int n;
	
	while( cin >> n ) {
		if (!n) break;
		
		int i, j;
		int cnt = 0;
		for( i = 1; i < n; i++ ) {
			int s = 0;
			for( j = 0; j < n; j++ ) {
				s += i+j;
				//i + … + i+j
				if ( s == n )
					cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}