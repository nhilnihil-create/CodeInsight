#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	string s,t;
	int a,b;
	string u;
	cin >> s >> t >> a >> b >> u;
	if(u == s){
		cout << a-1 << ' ' << b << endl;
	}else{
		cout << a << ' ' << b-1 << endl;
	}
}