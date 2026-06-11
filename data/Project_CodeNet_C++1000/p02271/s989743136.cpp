#include <iostream>
using namespace std;

int n, a[21];

int src(int i, int m){
	
	if (m == 0) return 1;
	if (m <= 0) return 0;
	if (i >= n) return 0;

	int act = src(i + 1, m) || src(i + 1, m - a[i]);
	return act;
}

int main(void){

	int q, m;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	cin >> q;
	for (int i = 0; i < q; i++){

		cin >> m;
		if (src(0, m)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}