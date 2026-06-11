#include<bits/stdc++.h>
using namespace std;

long long N, M;

int main(){
	cin >> N >> M;

	for(long long i = 0; i < M; i++) {
		long long tmp;
		cin >> tmp;
		N-=tmp;
	}
	if(N >= 0) {
		cout << N << endl;
	}else{
		cout << -1  << endl;
	}
}

