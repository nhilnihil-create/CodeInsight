#include<bits/stdc++.h>
using namespace std;

long long N;
long long u[200005];
long long v[200005];

int main(){
	cin >> N;
	for(long long i = 0; i < N - 1; i++) {
		cin >> u[i] >> v[i];
		u[i]--; v[i]--;
		if(u[i] > v[i]) {
			swap(u[i], v[i]);
		}
	}

	long long maxi = 0;

	for(long long i = 0; i < N; i++) {
		long long num = N-i;
		maxi += ((num) * (num+1))/2;
	}


	for(long long i = 0; i < N - 1; i++) {
		long long left = u[i];
		long long right = v[i];

		long long leftcount = left + 1;
		long long rightcount = N - right;
		maxi -= leftcount * rightcount;
	}
	cout << maxi << endl;

}
