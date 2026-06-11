#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int x;
	int sum = 0,count = 0;
	// nyuryoku
	cin >> x;
	// keisan
	sum = x;
	count = 1;
	while(sum % 360 != 0){
		sum += x;
		count++;
	}
	// syutsuryoku
	cout << count;
}