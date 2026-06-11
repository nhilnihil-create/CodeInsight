#include <iostream>
using namespace std;

int main() {
	int m,d;
	int d10,d1;
	int ans = 0;
	cin >> m >> d;
	for(int i=4; i<=m; i++){
		for(int j=22; j<=d; j++){
			d10 = j / 10;
			d1 = j - d10 * 10;
			if(d10 > 1 && d1 > 1){
				if(d10 * d1 == i){
					ans += 1;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}