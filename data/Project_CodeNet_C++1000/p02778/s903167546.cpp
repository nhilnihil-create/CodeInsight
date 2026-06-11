#include <iostream>
#include<string>
using namespace std;
int main(){
	string s,t;
	t.erase();
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++)
		t += "x";
	cout << t;
}