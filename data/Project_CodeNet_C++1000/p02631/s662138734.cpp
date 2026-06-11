#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	int a[N];
	int sum = 0;
	for(int i=0;i<N;i++){
		cin >> a[i];
		sum = sum ^ a[i];
	}
	for(int i=0;i<N;i++){
		cout << (sum ^ a[i]);
		if(i < N-1) cout << " ";
	}
	cout << endl;
}
