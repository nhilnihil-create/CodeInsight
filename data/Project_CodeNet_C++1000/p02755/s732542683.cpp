#include<bits/stdc++.h>
using namespace std;

long long A, B;

int main(){
	cin >> A >> B;

	for(long long i = 0; i < 100000; i++) {
		if(((long long)(i * 0.08)) == A && ((long long)(i * 0.1)) == B) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}