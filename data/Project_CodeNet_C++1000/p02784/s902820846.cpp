#include <bits/stdc++.h>
using namespace std;


int main() {
	int h, n;
	cin >> h >> n;
	while(n--){
		int a;
		cin >> a;
		if((h -= a) <=0){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}
