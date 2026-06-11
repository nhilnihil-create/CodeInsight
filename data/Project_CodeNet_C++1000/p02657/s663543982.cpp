#include <bits/stdc++.h>
#include <string>
using namespace std;
int intinput() {
	int x;
	cin >> x;
	return x;
}
vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	int a,b;
	a = intinput();
	b = intinput();
	cout << a * b << endl;
}