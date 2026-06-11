#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n;
	int ans = 0;
	cin >> n;
	while(true){
		n = n % 1000;
		if(n == 0){
			ans = 0;
			break;
			}
		else if(n < 1000 && n != 0){
			ans = 1000 - n;
			break;
			}
		}
	cout << ans;
	return 0;
}
