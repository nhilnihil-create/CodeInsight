#include <iostream>
#include <cstdio>
using namespace std;

string s;
int main() {
	cin >> s;
	if((int)s.size()%2) return puts("No")*0;
	for(int i=0; s[i]; i++) {
		if(i%2==0 && s[i]!='h' || i%2==1 && s[i]!='i') return puts("No")*0;
	}
	return puts("Yes")*0;
}