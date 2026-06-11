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
		if(s[1] == 'U'){
			cout << 7 << endl;
		}else{
			cout << 1 << endl;
		}
	}else if(s[0] == 'T'){
		if(s[1] == 'U'){
			cout << 5 << endl;
		}else{
			cout << 3 << endl;
		}
	}else if(s[0] == 'M'){
		cout << 6 << endl;
	}else if(s[0] == 'W'){
		cout << 4 << endl;
	}else{
		cout << 2 << endl;
	}
}