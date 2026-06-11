#include <iostream>
#include<string>
using namespace std;
int main(){
	int n;
	string s, t,a;
	a.erase();
	cin >>n>> s >> t;
	for (int i = 0; i < n; i++){
		a += s[i];
		a += t[i];
    }
	cout << a;
}