#include <iostream>
#include <string>
#include <cmath>
#include<iomanip>
#include<algorithm>
#include<list>
using namespace std;

int A[1000001];
int cnt;
int G[101];

void insertionSort(int n, int g){
	for (int i = g; i < n; i++){
		int v = A[i];
		int j = i - g;
		while (j >=0 && A[j] > v){
			A[j + g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = v;
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	cnt = 0;
	G[0] = 1;
	int m = 0;
	while(true){
		G[m + 1] = G[m] * 3 + 1;
		m++;
		if (G[m] > n){
			break;
		}
	}
	for (int i = m - 1; i >= 0; i--){
		insertionSort(n, G[i]);
	}
	cout << m << endl;
	for (int i = m - 1; i > 0; i--){
		cout << G[i] << " ";
	}
	cout << G[0] << endl;
	cout << cnt << endl;
	for (int i = 0; i < n; i++){
		cout << A[i] << endl;
	}
	return 0;
}