#include<bits/stdc++.h>
using namespace std;

long long N, K;
int main(){
	cin >> N >> K;
	set<long long> s;

	for(long long i = 0; i < K; i++) {
		long long d;
		cin >> d;
		for(long long j = 0; j < d; j++) {
			long long tmp;
			cin >> tmp;
			s.insert(tmp);
		}
	}
	cout << N - s.size() << endl;
}
