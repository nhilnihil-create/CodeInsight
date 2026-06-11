#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int d,n;
	// nyuryoku
	cin >> n >> d;
	// keisan
	int ans = 0,a = 0;
	while(a < n){
		a += 2*d + 1;
		ans++;
	}
	// syutsuryoku
	cout << ans;
}