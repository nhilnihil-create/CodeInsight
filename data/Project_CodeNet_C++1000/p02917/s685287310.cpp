#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	int N; cin>>N;
	vector<int> B(N-1),A(N);
	rep(i,N-1) cin>>B[i];

	for(int i=0; i<N; i++){
		int a=1e9,b=1e9;
		if(i-1>=0) a=B[i-1];
		if(i<N-1) b=B[i];
		A[i] = min(a,b); 
	}

	int sum=0;
	for(int x:A){
		// cerr << x << " ";
		sum += x;
	}
	cout << sum << endl;
}
