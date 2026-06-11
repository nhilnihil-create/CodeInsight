#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int cnt;

void insertionSort(int* A, int n, int g){
	for(int i = g; i < n; ++i){
		int v = A[i];
		int j = i - g;
		while(j >= 0 && A[j] > v){
			A[j + g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = v;
	}
}

int main() {
	int n;
	cin >> n;
	int A[n];
	for(int i = 0; i < n; ++i){
		cin >> A[i];
	}
	
	cnt = 0;
	int m = 8;
	int G[] = {3280, 1093, 364, 121, 40, 13, 4, 1};
	
	int um = 0;
	vector <int> uG;
	
	for(int i = 0; i < m; ++i){
		if(G[i] > n) continue;
		uG.push_back(G[i]);
		um++;
		if(i != m - 1) cout << " ";
		else cout << endl;
		insertionSort(A, n, G[i]);
	}
	cout << um << endl;
	for(int i = 0; i < um; ++i){
		cout << uG[i];
		if(i == um - 1) cout << endl;
		else cout << " ";
	}
	cout << cnt << endl;
	// cout << (cnt <= ceil(pow(n, 1.5))) << endl;
	for(int i = 0; i < n; ++i){
		cout << A[i] << endl;
	}
	return 0;
}