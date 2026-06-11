//============================================================================
// Name        : AOJCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 1000000;
static int cnt;


void trace(int A[],int n) {
	for (int j = 0; j < n; j++) {
		cout << A[j] << endl;
	}
}
void isort(int A[],int n, int g){
	for(int i = g; i < n; i++) {
		int v = A[i];
		int j = i - g;
		while(j >= 0 && A[j] > v) {
			A[j+g] = A[j];
			j=j-g;
			cnt++;
		}
		A[j+g] = v;
	}
}

int main() {


	int n;
	int A[MAX];

	cin >> n;

	for(int i=0; i < n; i++) {
		cin >> A[i];
	}

	cnt = 0;


	int m=1;
	for (int i = n/3/3; i > 0; i/=3) {
		m++;
	}
	int G[m];
	int d = 3;
	G[m-1] = 1;
	for(int i = m-2; i >= 0; i--,d*=3) {
		G[i] = G[i+1] + d;
	}
	for(int i = 0; i < m; i++) {

		isort(A, n,G[i]);
	}
	cout << m << endl;
	for(int i = 0; i < m-1; i++) {
		cout << G[i] << " ";
	}
	cout << G[m-1] << endl;
	cout << cnt << endl;
	trace(A,n);



}



