#include<bits/stdc++.h>
using namespace std;

long long X;

int main(){
	cin >> X;

	long long cur = 100;

	for(long long i = 1; i >= 0; i++) {
		//cur = (long long)(cur * 1.01);
		cur += cur/100;
		if(cur >= X) {
			cout << i << endl;
			return 0;
		}
	}

}

