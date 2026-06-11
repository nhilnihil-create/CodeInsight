#include<bits/stdc++.h>
using namespace std;

long long N, K;
long long A[200005];
long long dis[200005];

int main(){
	cin >> N >> K;
	for(long long i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
		dis[i] = -1;
	}


	long long cur = 0;
	long long cost = 0;
	long long rest = K;
	dis[0] = 0;
	bool skiped = false;

	while(rest) {
		//次の街に進む
		cur = A[cur];
		cost++;
		rest--;
		//cout << "cur = " << cur << " cost " << cost << " rest " << rest << endl;

		//loop発見
		if(!skiped && dis[cur] >= 0) {
			skiped = true;
			long long syuki = cost - dis[cur];
			//cout << "syuki " << syuki << endl;

			//ワープ
			//cout << "change rest from " << rest;
			rest %= syuki;
			//cout << " to " << rest << endl;
		}
		dis[cur] = cost;
	}
	cout << cur + 1 << endl;
}
