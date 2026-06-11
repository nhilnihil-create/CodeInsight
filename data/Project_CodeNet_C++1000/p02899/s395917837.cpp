#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int N;
	cin >> N;
	int a[N+1];
	int tmp;
	rep(i,N) {
		cin >> tmp;
		a[tmp] = i+1;
	}
	for (int i = 1; i <= N; i++) {
		cout << a[i] << endl;
	}


	return 0;
}
