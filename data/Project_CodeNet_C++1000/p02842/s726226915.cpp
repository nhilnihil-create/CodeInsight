#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int N;
	cin >> N;
	int M = N/1.08 - 1;
	
	rep(i,10){
		M += 1;
		if (int(M*1.08) == N) {
			cout << M << endl;
			return 0;
		}
	}
	cout << ":(" << endl;




	return 0;
}
