#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

int cnt = 0;

void insertionSort(vector<int> &A, int n, int g){
	for(int i = g; i < n; i++){
		int v = A[i];
		int j = i - g;
		while(j >= 0 && A[j] > v){
			A[j+g] = A[j];
			j -= g;
			cnt++;
		}
		A[j+g] = v;
	}
}

void shellSort(vector<int> &A, int n){
	vector<int> g;
	int m;
	for(int i = 1; i <= n; i = 3 * i + 1)
		g.push_back(i);
	m = g.size();
	cout << m << endl;
	for(int i = m - 1; i >= 0; i--){
		cout << g[i];
		if(i == 0) cout << endl;
		else cout << " ";  
		insertionSort(A,n,g[i]);
	}
}

int main(){
	int n;
	vector<int> v;
	cin >> n;
	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	shellSort(v,n);
	cout << cnt << endl;
	for(int i = 0; i < n; i++)
		cout << v[i] << endl;	
}