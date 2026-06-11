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
	bool bad = false;
	string s;
	cin >> s;
	for(int i = 0;i < 3;i++){
		if(s[i] == s[i+1]) bad = true;
	}
	if(bad){
		cout << "Bad" << endl;
	}else{
		cout << "Good" << endl;
	}
}