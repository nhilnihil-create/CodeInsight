#include <iostream>
using namespace std;

int main() {
	int l,r,d;cin >>l>>r>>d;
	int out = r/d - l/d;
	if(l%d==0) ++out;
	cout << out << endl;
	return 0;
}