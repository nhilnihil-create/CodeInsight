#include <bits/stdc++.h>

using namespace std;

int main(void){
	int N, K, S; 
	cin >> N >> K >> S;
	if (S != 1000000000){
		for (int i = 0; i < K; ++i)
			cout << S << " ";
		for (int i = K; i < N; ++i)
			cout << (1000000000) << " ";
	}
	else{
		for (int i = 0; i < K; ++i)
			cout << (1000000000) << " ";
		for (int i = K; i < N; ++i)
			cout << "1 ";
	}
	cout << endl;
	return 0;
}