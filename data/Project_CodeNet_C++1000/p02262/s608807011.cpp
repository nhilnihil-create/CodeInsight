#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <map>
#include <algorithm>

using namespace std;

template< typename T>
void print(const vector<T> &data) {
	if (data.empty()) return;
	for (int i = 0; i < data.size(); ++i) {
		cout << data[i];
		if (i != data.size() - 1) cout << " ";
		else cout << endl;
	}
}

long long cnt = 0;
int l;
int A[1000000];
int n;
vector<int> G;

void insSort(int A[], int n, int g){
	for (int i = g; i < n; ++i){
		int v = A[i];
		int j = i - g;
		while (j >= 0 && A[j]>v)
		{
			A[j + g] = A[j];
			j -= g;
			cnt++;
		}
		A[j + g] = v;
	}
}

void shellSort(int A[], int n){
	for (int h = 1;;){
		if (h > n) break;
		G.push_back(h);
		h = 3 * h + 1;
	}

	for (int i = G.size() - 1; i >= 0; --i){
		insSort(A, n, G[i]);
	}
}


int main(){
	cin >> n;
	for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
	cnt = 0;

	shellSort(A, n);

	cout << G.size() << endl;
	for (int i = G.size() - 1; i >= 0; --i){
		printf("%d", G[i]);
		if (i) printf(" ");
	}
	printf("\n");
	printf("%d\n", cnt);
	for (int i = 0; i < n; ++i) printf("%d\n", A[i]);

	return 0;
}