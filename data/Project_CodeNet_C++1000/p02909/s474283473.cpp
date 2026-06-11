#include <iostream>
#include <cstdio>
using namespace std;

string s;
int main() {
	cin >> s;
	if(s=="Sunny") puts("Cloudy");
	else if(s=="Cloudy") puts("Rainy");
	else puts("Sunny");
	return 0;
}
