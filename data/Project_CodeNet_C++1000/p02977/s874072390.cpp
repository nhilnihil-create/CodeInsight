#include <iostream>
using namespace std;

int a[200010], b[200010];

int main() {
	int N;
	cin >> N;
	for(int i=1; i<=N; i <<= 1){
		if(i==N){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	for(int i=0; i<2; ++i){
		a[i*2]=i+1, b[i*2]=i+2;
		a[i*2+1]=i+1+N, b[i*2+1]=i+2+N;
	}
	a[4]=3, b[4]=N+1;
	int fn=5;
	for(int i=4; i<N; i += 2){
		a[fn]=1, b[fn]=i;
		a[fn+1]=1, b[fn+1]=i+1;
		a[fn+2]=i, b[fn+2]=i+1+N;
		a[fn+3]=i+1, b[fn+3]=i+N;
		fn += 4;
	}
	if(N%2==0){
		int d=1;
		while((N&d)==0) d <<= 1;
		a[fn]=N, b[fn]=d;
		a[fn+1]=N*2, b[fn+1]=N-d+1;
		fn += 2;
	}
	for(int i=0; i<fn; ++i) cout << a[i] << ' ' << b[i] << endl;
	return 0;
}