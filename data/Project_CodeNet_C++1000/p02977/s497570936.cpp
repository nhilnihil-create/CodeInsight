#include<bits/stdc++.h>
using namespace std;

int main(){
	int N; cin >> N;
	if(1 << (int)(log2(N + 0.1)) == N){puts("No"); return 0;}
	puts("Yes");
	for(int i = 1 ; i < 3 ; ++i){
		cout << i << ' ' << i + 1 << endl;
		cout << i + N << ' ' << i + N + 1 << endl;
	}
	cout << 3 << ' ' << N + 1 << endl;
	for(int i = 4 ; i < N ; i += 2){
		cout << i << ' ' << i + 1 << endl;
		cout << i + 1 << ' ' << N + 1 << endl;
		cout << N + 1 << ' ' << i + N << endl;
		cout << i + N << ' ' << i + N + 1 << endl;
	}
	if(!(N & 1)){
		int t = 1 << (int)(log2(N + 0.1));
		cout << N << ' ' << t + N << endl; cout << N - t + 1 << ' ' << 2 * N << endl;
	}
	return 0;
}