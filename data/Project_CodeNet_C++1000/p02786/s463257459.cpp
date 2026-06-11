#include <bits/stdc++.h>
using namespace std;

int main(){
	long long H;
	cin >> H;
	long long num = 1;
	long long ans = 0;
	while(H > 0){
		H /= 2;
		ans += num;
		num *= 2;
	}
	cout << ans << endl;
}
