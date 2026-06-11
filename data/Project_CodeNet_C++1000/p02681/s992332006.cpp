#include <iostream>
#include <string>
using namespace std;

int main() {
	string s,t;cin >>s>>t;
	auto subt = t.substr(0,t.size()-1);
	if(subt == s){
		cout << "Yes" << endl; 
	} else {
		cout << "No" << endl; 
	} 
	return 0;
}