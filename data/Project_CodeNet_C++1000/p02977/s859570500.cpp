#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	if(n < 3) cout << "No" << endl;
	else {
		if((n & - n) == n) cout << "No" << endl;
		else {
			cout << "Yes" << endl;
			cout << 1 << " " << 2 << endl;
			cout << 2 << " " << 3 << endl;
			cout << 3 << " " << 1 + n << endl;
			cout << 1 + n << " " << 2 + n << endl;
			cout << 2 + n << " " << 3 + n << endl;
			for(int i = 4; i <= n; i += 2){
				if(i + 1 > n){
					for(int j = 2; j < n; j++){
						int cmp = i ^ j ^ 1;
						if(cmp >= 2 && cmp < n){
							cout << j << " " << i << endl;
							cout << cmp + n << " " << i + n << endl;
							break;
						}
					}
				} else {
					cout << 1 << " " << i << endl;
					cout << i << " " << i + 1 << endl;
					cout << 1 << " " << i + 1 + n << endl;
					cout << i + 1 + n << " " << i + n << endl;
				}
			}
		}
	}
	return 0;
}
