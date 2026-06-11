#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ans = -1;
	for (int i = 0; i <= n; i++){
		if ( floor( i*1.08) == n){
			ans = i;
		}
	}
	if (ans == -1){
		cout << ":(";
	}
	else {
		cout << ans;
	}
}