#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


#define abs(N) ((N>0)?N:-1*N)
#define lt(A,B) ((A>B)?B:A)
#define gt(A,B) ((A<B)?B:A)
#define print(S) (cout << S)
#define println(S) (cout << S << endl)

long long cnt;
int m;
vector<int> G;

void insertionSort(int * A, int n, int g){
	for (int i = g; i < n; ++i) {
		int v = A[i];
		int j = i - g;
		while(j >= 0 && A[j] > v){
			A[j+g] = A[j];
			j = j-g;
			cnt++;
		}
		A[j+g] = v;
	}
}

void shellSort(int * A, int n){
	int i=1;
	m = 0;
	cnt = 0;
	while(i <= n){
		G.insert(G.begin(),i);
		m++;
		i = i * 3 + 1;
	}
	for (vector<int>::iterator itr = G.begin(); itr != G.end(); ++itr) {
		insertionSort(A,n,(*itr));
	}
}

int main(){
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}

	shellSort(A,n);

	println(m);
	for (vector<int>::iterator itr = G.begin(); itr != G.end(); ++itr) {
		cout << (*itr) << " ";
	}
	cout << endl;
	println(cnt);

	for (int i = 0; i < n; ++i) {
//		if(i > 0) cout << " ";
		cout << A[i] << endl;
	}
//	cout << endl;

	return 0;
}

