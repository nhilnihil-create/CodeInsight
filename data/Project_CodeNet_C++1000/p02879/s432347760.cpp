#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	int a,b;
	cin >> a >> b;
	if(a <= 9 && b <= 9){
		cout << a*b << endl;
	}else{
		cout << -1 << endl;
	}
}