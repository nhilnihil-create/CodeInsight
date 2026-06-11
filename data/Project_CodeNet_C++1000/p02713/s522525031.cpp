#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b,int c){
	return __gcd(__gcd(a,b),c);
}
int main(){
	int k,ans = 0;
	cin >> k;
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= k; j++){
			for(int g = 1; g <= k; g++){
				ans += gcd(i,j,g);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
