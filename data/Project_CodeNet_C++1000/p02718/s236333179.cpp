#include<bits/stdc++.h>
using namespace std;

int main(){
	long long N, M;
	double sum = 0;
	double a[105];
	cin >> N >> M;
	for(long long i = 0; i < N; i++) {
		cin >> a[i];
		sum += a[i];
	}


	long long num = 0;
	for(long long i = 0; i < N; i++) {
		if(a[i]/sum >= 1.0/(4.0 * M)) {
			num++;
		}
	}
	if(num >= M) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}