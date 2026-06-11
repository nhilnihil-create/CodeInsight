#include <iostream>

using namespace std;
int main() {
	int n, m;
	cin >> n;
	int A[n];
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	int G[n];
	int i = 1;
	int j = 0;
	while(i <= n){
		G[j] = i;
		i = 3*i+1;
		j++; 
	}
	m = j; 
	cout << m << endl;
	for(int i = m-1; i > 0; i--){
		cout << G[i] << " ";
	}
	cout << G[0] << endl;
	int cnt = 0; 
	for(int k = m-1; k >= 0; k--){
		for(int i = G[k]; i < n; i++){
			int v = A[i];
			int j = i - G[k];
			while(j >= 0 && A[j] > v){
				A[j+G[k]] = A[j];
				j = j-G[k];
				cnt++;
			}
			A[j + G[k]] = v;
		}
	}	
	cout << cnt << endl;
	for(int i = 0; i < n; i++){
		cout << A[i] << endl;
	}
	return 0;
}
