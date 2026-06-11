#include <iostream>
#include <cstdio>
using namespace std;

string s, a[9] = {"", "SAT", "FRI", "THU", "WED", "TUE", "MON", "SUN"};
int main() {
	int i;
	cin >> s;
	for(i=1; i<=7; i++) if(a[i]==s) break;
	cout << i;
	return 0;
}
