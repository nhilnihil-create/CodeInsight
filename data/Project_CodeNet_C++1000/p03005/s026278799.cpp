#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k, ans;
	cin >> n >> k;
	if(k == 1 || n == k) ans = 0;
	else ans = n - k;
	cout << ans << endl;
}