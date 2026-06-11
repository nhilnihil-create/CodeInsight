#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; vector <char>k;
int main(){
	string t; cin >> t; 
	for (int i=0;i<t.size();i++){
		if(t[i]=='?') k.push_back('D');
		else k.push_back(t[i]);
	}
	for (int i=0; i<t.size(); i++) cout << k[i];
}
