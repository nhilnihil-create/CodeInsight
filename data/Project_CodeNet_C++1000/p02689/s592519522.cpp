#include<bits/stdc++.h>
using namespace std;

long long N, M;
long long H[100005];
long long A[100005];
long long B[100005];
bool good[100005];

int main(){
	cin >> N >> M;
	for(long long i = 0; i < N; i++) {
		cin >> H[i];
		good[i] = true;
	}
	for(long long i = 0; i < M; i++) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
	}

	for(long long i = 0; i < M; i++) {
		if(H[A[i]] < H[B[i]]) {
			good[A[i]] = false;
		} else if (H[A[i]] == H[B[i]]) {
			good[A[i]] = false;
			good[B[i]] = false;
		} else {
			good[B[i]] = false;
		}
	}

	long long ans = 0;
	for(long long i = 0; i < N; i++) {
		if(good[i]) ans++;
	}
	cout << ans << endl;
}
