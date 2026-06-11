#include<iostream>
using namespace std;
int main() {

	//C
	int n, m;
	cin >> n >> m;
	int AC[100000];
	int WA[100000];
	int i, p;
	for (i = 0; i < n; i++) {
		AC[i] = 0;
		WA[i] = 0;
	}

	string s;
	for (i = 0; i < m; i++) {
		cin >> p;
		cin >> s;
		if (s == "AC") {
			AC[p - 1]++;
		}else{
			if(AC[p-1]==0)WA[p - 1]++;
		}
	}
	int pn = 0, sc = 0;
	for (i = 0; i < n; i++) {
		if (AC[i] > 0) {
			sc++;
			pn += WA[i];
		}
	}
	cout << sc << ' ' << pn << endl;
	return 0;

	//B
	/*int n, k, m;
	cin >> n >> k >> m;
	int sum = 0, a, i;
	for (i = 0; i < n - 1; i++) {
		cin >> a;
		sum += a;
	}
	for (i = 0; i <= k; i++) {
		if (sum + i >= n * m) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
*/	
	
	
	
	//A

	/*char c;
	cin >> c;
	cout << (char)(c + 1) << endl;
	return 0;*/
}