#include <bits/stdc++.h>
using namespace std;

vector<int> forintinput(int n) {
	vector<int> x(100000);
	for(int i = 0;i < n;i++) cin >> x[i];
	return x;
}
int main(){
	string s;
	cin >> s;
	if(s[0] == 'S'){
		cout << "Cloudy" << endl;
	}else if(s[0] == 'C'){
		cout << "Rainy" << endl;
	}else{
		cout << "Sunny" << endl;
	}
}