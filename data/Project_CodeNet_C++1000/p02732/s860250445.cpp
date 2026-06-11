#include<bits/stdc++.h>
using namespace std;

long long A[200005];
map<long long, long long> memo;
int main(){
	long long N;
	cin >> N;
	for(long long i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
		memo[A[i]]++;
	}

	long long base = 0;
	for(auto item: memo) {
		base += ((item.second) * (item.second - 1)) /2;
	}

	for(long long i = 0; i < N; i++) {
		long long num = A[i];
		cout << base - (memo[num] * (memo[num] - 1) / 2) + ((memo[num] - 1) * (memo[num] - 2) / 2) << endl;
	}




}
