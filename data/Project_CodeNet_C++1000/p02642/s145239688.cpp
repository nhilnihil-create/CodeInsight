#include<bits/stdc++.h>
using namespace std;

long long N;
vector<long long> A;

int main(){
	cin >> N;
	for(long long i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	long long ans = 0;
	set<long long> numset;
	sort(A.begin(), A.end());

	for(long long i = 0; i < A.size(); i++) {

		long long num = A[i];

		bool ok = true;

		if(i > 0 && num == A[i-1]) {
			ok = false;
		}

		if(i < A.size() - 1 && num == A[i+1]) {
			ok = false;
		}





		for(long long j = 1; j * j <= num; j++) {
			if(num%j == 0){
				if(numset.count(j)>0) {
					ok = false;
					break;
				}
				if(numset.count(num/j)>0) {
					ok = false;
					break;
				}
			}
		}

		if(ok) {
			ans++;
		}

		numset.insert(num);
	}
	cout << ans << endl;
}
