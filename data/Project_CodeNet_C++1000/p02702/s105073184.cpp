#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	string s;
	// nyuryoku
	cin >> s;
	int n = s.size();
	int val[2019] = {};
	// keisan
	LL mul = 1;
	LL rem = 0;
	val[rem]++;
	LL ans = 0;
	for(int i=0;i<n;i++){
		LL add = s[n-1-i] - '0';
		rem = (rem + add*mul)%2019;
		mul = (mul*10)%2019;
		val[rem]++;
	}
	for(int i=0;i<2019;i++){
		ans += val[i]*(val[i]-1)/2;
	}
	// syutsuryoku
	cout << ans << endl;
}