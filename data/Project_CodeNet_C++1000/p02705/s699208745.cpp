#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	int r;
	cin >> r;
	const double PI = acos(-1);
	cout << r * 2 * PI << endl;
}