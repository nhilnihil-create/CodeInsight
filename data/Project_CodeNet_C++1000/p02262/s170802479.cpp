#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

void insertionSort(vector<int> &a, int n, int g, int &cnt){
	int v, j;
	for (int i = g; i < n; i++){
		v = a[i];
		j = i - g;
		while (j >= 0 && a[j] > v){
			a[j + g] = a[j];
			j -= g;
			cnt++;
		}
		a[j + g] = v;
	}
}

int shellSort(vector<int> &a, vector<int> G, int m, int n){
	int cnt = 0;
	for (int i = 0; i < m; i++){
		insertionSort(a, n, G[i], cnt);
	}
	return cnt;
}

int main(){
	int n, m, cnt;
	cin >> n; 
	vector<int> a(n), G(100);
	for (int i = 0; i < n; i++) cin >> a[i];
	G[0] = 1;
	for (int i = 1; i < 100; i++) G[i] = 3 * G[i - 1] + 1;
	for (m = 0; n >= G[m]; m++);
	reverse(G.begin(), G.begin() + m);
	cout << m << endl;
	for (int i = 0; i < m; i++){
		cout << G[i];
		if (i != m - 1) cout << " ";
	}
	cnt = shellSort(a, G, m, n);
	cout << endl << cnt << endl;
	for (int i = 0; i < n; i++) cout << a[i] << endl;
}