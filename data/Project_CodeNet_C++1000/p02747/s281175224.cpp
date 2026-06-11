#include<bits/stdc++.h>

using namespace std;

string s;

int main(){
	cin >> s;
	if(s.size()%2){
		cout << "No" << endl;
		return 0;
	}
	for(int i = 0; i < s.size()-1; ++i){
		if(i%2) continue;
		if(s[i] != 'h' || s[i+1] != 'i'){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}