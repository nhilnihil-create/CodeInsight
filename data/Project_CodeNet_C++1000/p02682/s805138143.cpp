#include<bits/stdc++.h>
using namespace std;

long long A, B, C, K;
int main(){
	cin >> A >> B >> C >> K;

	if(A + B >= K) {
		cout << min(A, K) << endl;
	} else {
		cout << A - (K - (A+B)) << endl;
	}
}
