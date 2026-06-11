#include<bits/stdc++.h>
using namespace std;

long long N, M;

int main(){
	cin >> N >> M;
	long long rest = M;

	long long small = 1;
	long long large = M;
	while(rest > 0 && small < large) {
		cout << small << " " << large << endl;
		small++;
		large--;
		rest--;
	}
	small = M+1;
	large = 2*M+1;
	while(rest > 0 && small < large) {
		cout << small << " " << large << endl;
		small++;
		large--;
		rest--;
	}
}