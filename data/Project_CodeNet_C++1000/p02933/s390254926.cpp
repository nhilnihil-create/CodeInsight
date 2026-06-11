#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	int a;
	string s;
	cin >> a >> s;
	if(a >= 3200){
		cout << s << endl;
	}else{
		cout << "red" << endl;
	}
}