#include "iostream"

using namespace std;

void sonyu( int num, int g, int* cnt, int a[1000000] ) {

	for (int i = 1; i < num; i++) {

		int v = a[i];
		int j = i - g;

		while (j >= 0 && a[j] > v) {
			a[j + g] = a[j];
			j-=g;
			*cnt+=1;
		}
		a[j + g] = v;

	}
}

int main() {

	int a[1000000];
	int cnum;
	int num;
	int cnt = 0;

	cin >> num;
	
	for (int i = 0; i < num; i++) {
		cin >> a[i];
	}

	int kaisu = 1;
	int v[100];
	v[0] = 1;
	for (int i = 1; ; i++) {
		v[i] = v[i-1] * 3 + 1;
		if (v[i] > num) break;
		kaisu++;
	}

	cout << kaisu << endl;
	
	for (int i = kaisu - 1; i >= 0; i--) {
		sonyu(num, v[i], &cnt, a);
		cout << v[i];
		if (i != 0) cout << " ";
	}
	cout << endl;

	cout << cnt << endl;
	
	for (int j = 0; j < num; j++) {
		cout << a[j] << endl;
	}
	
	int p = 0;
	return 0;
}