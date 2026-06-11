#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void swap(int &a, int &b){
	int dum = a;
	a = b;
	b = dum;
	return;
}

int cnt;

void insertionSort(vector<int> &a, int g){
	int n = a.size();
	for (int i = g; i != n; i++){
		int v = a[i];
		int j = i - g;
		while (j >= 0 && a[j] > v){
			a[j + g] = a[j];
			j = j - g;
			cnt++;
		}
		a[j + g] = v;
	}
}

void shellSort(vector<int> &a){
	cnt = 0;
	int n = a.size();
	int m = (n == 1 ? 1 : (int)log2(n));
	vector<int> G(m);
	cout << m << endl;
	for (int i = 0; i != m; i++){
		G[i] = (int)pow(2, m - i - 1);
		cout << (i == 0 ? "" : " ") << G[i];
		insertionSort(a, G[i]);
	}
	cout << endl;
	return;
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i != n; i++) cin >> a[i];

	shellSort(a);

	cout << cnt << endl;
	for (int i = 0; i != n; i++) cout << a[i] << endl;
}
