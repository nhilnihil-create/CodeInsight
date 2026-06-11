#include <iostream>

using namespace std;

int main(){
	int N, i, j, k;
	cin >> N;
	int A[N];
	for(i = 0; i < N; i++){
		cin >> A[i];
	}

//	1  insertionSort(A, n, g)
//	2      for i = g to n-1
//	3          v = A[i]
//	4          j = i - g
//	5          while j >= 0 && A[j] > v
//	6              A[j+g] = A[j]
//	7              j = j - g
//	8              cnt++
//	9          A[j+g] = v
//	10
//	11 shellSort(A, n)
//	12     cnt = 0
//	13     m = ?
//	14     G[] = {?, ?,..., ?}
//	15     for i = 0 to m-1
//	16         insertionSort(A, n, G[i])
	int g, v, m = 1, cnt = 0;
	int G[13] = {0};
	G[0] = 1;
	while((g = 3*G[m-1]+1) < N){
		G[m] = g;
		m++;
	}
	for(k = m-1; k >= 0; k--){
		g = G[k];
		//insertionSort;
		for(i = g; i < N; i++){
			v = A[i];
			j = i - g;
			while(j >= 0 && A[j] > v){
				A[j+g] = A[j];
				j = j - g;
				cnt++;
			}
			A[j+g] = v;
		}
	}

	cout << m << endl << G[m-1];
	for(i = m-2; i >= 0; i--){
		cout << ' ' << G[i];
	}
	cout << endl << cnt << endl;
	for(i = 0; i < N; i++){
		cout << A[i] << endl;
	}

	return 0;
}
