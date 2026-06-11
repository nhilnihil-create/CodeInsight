#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool foo(pair < int, int > A){
	return (A.first == A.second);
}

int main(){
	int N; cin >> N;
	vector < pair < int, int > > A(N);
	for (int i = 0; i < N; i ++){
		int X, Y; cin >> X >> Y;
		A[i] = {X, Y};
	}
	bool ok = 0;
	for (int i = 2; i < N; i ++){
		if (foo(A[i]) && foo(A[i - 1]) && foo(A[i - 2])){
			ok = 1;
			break;
		}
	}
	cout << (ok ? "Yes" : "No") << "\n";
}