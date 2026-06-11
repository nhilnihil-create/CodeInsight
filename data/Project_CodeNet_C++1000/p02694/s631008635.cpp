#include <bits/stdc++.h>
using namespace std;

int main(){
	long long X;
	cin >> X;
	long long N = 100;
	int nen = 0;
	while(X > N){
		nen++;
		N += N / 100;
	}
	cout << nen << endl;
}
