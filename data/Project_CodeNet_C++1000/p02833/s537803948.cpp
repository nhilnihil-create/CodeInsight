#include<bits/stdc++.h>
using namespace std;

int main(){
	// sengen
	long long n;
	// nyuryoku
	cin >> n;
	// keisan
	if(n%2 == 1){
		cout << '0';
		return 0;
	}
	if(n < 10){
		cout << '0';
		return 0;
	}
	long long count = 0;
	long long wari = 10;
	while(n >= wari){
		long long keep = n;
		keep = keep/wari;
		count += keep;
		wari *= 5;
	}
	// syutsuryoku
	cout << count;
}