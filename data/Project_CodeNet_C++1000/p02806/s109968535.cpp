#include<iostream>
#include<string>
#include<cmath>
using namespace std;




int main() {
	string str;
	int N;
	string *s;
	int *t;
	string X;
	cin >> N;
	s = new string[N];
	t = new int[N];
	for (int i = 0;i < N;i++) {
		cin >> s[i] >> t[i];
	}
	cin >> X;
	
	int sum = 0;
	bool flag = false;
	for (int i = 0;i < N;i++) {
		if (flag)sum += t[i];
		if (s[i] == X)flag = true;
		
	}
	cout << sum << endl;

}