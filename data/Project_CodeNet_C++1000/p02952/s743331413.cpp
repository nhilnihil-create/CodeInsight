#include<iostream>
#include<cmath>
using namespace std;

int numDigits(int n){
	int digits = 0;
	while(n>0){
		digits++;
		n = n/10;
	}
	return digits;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	for(int i=1; i<=n; i++){
		if(numDigits(i)%2) ans++;
	}
	cout << ans;
	return 0;
}