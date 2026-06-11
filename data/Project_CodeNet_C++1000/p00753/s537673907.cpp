#include <bits/stdc++.h>
using namespace std;

#define SIZE 3000000
int prime[SIZE];

int main(){
	for(int i = 0; i < SIZE; i++){
		prime[i] = 1;
	}

	for(int i = 2; i * i < SIZE; i++){
		if(prime[i]){
			for(int j = i + i; j < SIZE; j += i){
				prime[j] = 0;
			}
		}
	}
	int N;
	while(cin >> N, N){
		int cnt = 0;
		for(int i = N + 1; i <= 2 * N; i++){
			cnt += prime[i];
		}
		cout << cnt << endl;
	}
}