#include<bits/stdc++.h>
using namespace std;

long long a[200005];
long long alla;

int main(){
	long long N;
	cin >> N;
	for(long long i = 0; i < N; i++) {
		cin >> a[i];
		alla ^= a[i];
	}

	for(long long i = 0; i < N; i++) {
		cout << (alla^a[i]);
		if(i != N-1 ) {
			cout << " ";
		} else {
			cout << endl;
		}
	}
}
