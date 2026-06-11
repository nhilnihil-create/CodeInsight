#include <bits/stdc++.h>

using namespace std;

int main(){
	string a,b;
	cin >> a >> b;
	int ans = 0;
	for(int i = 0; i < a.size(); i++){
		ans += (a[i] != b[i]);
	}
	cout << ans << "\n";
	return 0;
}
