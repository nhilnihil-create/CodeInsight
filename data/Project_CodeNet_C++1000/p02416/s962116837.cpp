#include <iostream>
#include <string>
using namespace std;

int main() {
	int ans;
	string str;
	do {
		getline(cin,str);
		if (str=="0") break;
		for(unsigned int i=0;i<str.length();++i) {
			ans+=str[i]-'0';
		}
		cout << ans << endl;
		ans=0;
	} while(1);
	return 0;
}