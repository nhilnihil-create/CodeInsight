#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	for(int i = 0; i <= k; i++){
		for(int j = 0; j <= k; j++){
			for(int l = 0; l <= k; l++){
				if(i + j + l <= k && a * (1 << i) < b * (1 << j) && b * (1 << j) < c * (1 << l)){
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
}
