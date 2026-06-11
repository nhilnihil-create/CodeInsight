#include <bits/stdc++.h>
using namespace std;	
void func(long long a){
	long long denom = 10;
	long long ans = 0;
	if(a % 2 != 0){
		cout << ans << endl;
	} else {
		ans += a / 10;
		a /= 10;
		while(a){
			ans = ans + (a / 5);
			a = a / 5;
		}
		cout << ans << endl;
	}
			
}



int main(){
	long long n;
	cin >> n;
	func(n);
}
