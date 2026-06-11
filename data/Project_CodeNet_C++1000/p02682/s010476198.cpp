#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x;
	for(int i = 0;i < n;i++){
		int ia;
		cin >> ia;
		x.push_back(ia);
	}
	return x;
}
int main(){
	int a,b,c,k;
	cin >> a >> b >> c >> k;
	if(k <= a) cout << k << endl;
	else if(k <= a + b) cout << a << endl;
	else cout << a - (k - a - b) << endl;
	return 0;
}