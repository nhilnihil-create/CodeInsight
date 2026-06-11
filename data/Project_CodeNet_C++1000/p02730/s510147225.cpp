#include<iostream>
#include<string>
using namespace std;

bool isPalin(string S){
	string t = S;
	reverse(t.begin(),t.end());
	return S == t;
}

int main(){
	string s;
	cin >> s;
	bool ans = true;
	if(!isPalin(s)) ans = false;
	if(!isPalin(s.substr(0,s.size()/2))) ans = false;
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
