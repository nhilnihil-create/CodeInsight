#include <bits/stdc++.h>
using namespace std;

int main(){
	int H, A;
	cin >> H >> A;
	int ans = H / A;
	if(H % A > 0)ans++;
	cout << ans << endl;
}
