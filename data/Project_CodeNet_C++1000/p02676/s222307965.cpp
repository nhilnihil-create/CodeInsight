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
	int k;
	string s;
	cin >> k >> s;
	if(s.length() > k){
		for(int i = 0;i < k;i++){
			cout << s[i];
		}
		cout << "..." << endl;
	}else{
		for(int i = 0;i < s.length();i++){
			cout << s[i];
		}
		cout << "\n";
	}
}