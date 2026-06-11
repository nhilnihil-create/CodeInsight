#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	string w;
	cin >> w;
	transform(w.begin(),w.end(),w.begin(),::toupper);
	int c = 0;
	while(1){
		string s;
		cin >> s;
		if(s=="END_OF_TEXT") break;
		transform(s.begin(),s.end(),s.begin(),::toupper);
		if(s==w) c++;
	}
	cout << c << endl;
}