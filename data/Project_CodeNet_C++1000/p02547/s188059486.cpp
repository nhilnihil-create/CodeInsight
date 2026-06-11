#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int seq = 0;
	bool ans = false;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		seq = (a == b) ? seq + 1 : 0;
		if(seq >= 3) ans = true;
	}
	cout << (ans ? "Yes\n" : "No\n");
	return 0;
}
