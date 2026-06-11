#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	vector<int> A(m);
	for(int i = 0; i < m; i++){
		cin >> A[i];
	}
	int answer = n;
	for(int i = 0; i < m; i++){
		answer = answer - A[i];
	}
	if(answer >= 0){
		cout << answer;
	} else {
		cout << -1;
	}
}