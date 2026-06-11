#include <bits/stdc++.h>
using namespace std;

int main(){
	long long N, K;
	cin >> N >> K;
	vector<long long> A;
	long long MAX = 0;
	for(int i=0;i<N;i++){
		long long X;
		cin >> X;
		A.push_back(X);
		MAX = max(X, MAX);
	}
	long long r = MAX, l = 1;
	while(l < r){
		long long mid = (l + r) / 2;
		long long tmp = 0;
		for(int i=0;i<N;i++){
			tmp += (A[i] - 1) / mid;
		}
		if(tmp <= K){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << l << endl;
}
