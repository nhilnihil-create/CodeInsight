#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, total = 0, n_pairs;
	cin >> N;
	for(int i = 1; i < N; ++i){
		if(N % i == 0){
			n_pairs = N/i - 1;
		}
		else{
			n_pairs = N/i;
		}
		total += n_pairs;
	}
	cout << total;
}
