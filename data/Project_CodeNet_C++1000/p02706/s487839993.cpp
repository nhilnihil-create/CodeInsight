#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	int A[M];
	for(int i=0;i<M;i++){
		cin >> A[i];
		N -= A[i];
	}
	if(N < 0)N = -1;
	cout << N << endl;
}
