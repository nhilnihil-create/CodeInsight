#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#define ll long long int
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
	ll N, M, K, count=0, conb;

	cin >> N >> M >> K;
	vector<ll> a(N), b(M), numa(N+1), numb(M+1);

	for (int i = 0; i < N; i++){
		cin >> a[i];
	}
	for (int i = 0; i < M; i++){
		cin >> b[i];
	}

	numa[0] = 0;
	numb[0] = 0;
	for (int i = 0; i < N; i++){
		numa[i + 1] = numa[i] + a[i];
	}
	for (int i = 0; i < M; i++){
		numb[i + 1] = numb[i] + b[i];
	}

	conb = M;
	for (int i = 0; i <= N; i++){
		if (numa[i] > K) break;
		for (int j = conb; j >=0; j--){
			if (numb[j] <= (K-numa[i])){
				conb = j;
				j = -1;
			}
			else if (j == 0){
				conb = 0;
			}
		}
		if (count < (i + conb))
			count = i + conb;
	}

	cout << count << endl;

	return 0;
}