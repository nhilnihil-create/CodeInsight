#include <iostream>
using namespace std;

int main() {
	int n;cin >>n;
	int out = 0;
	for (int i=0;i<n;++i){
		int t;cin>>t;
		if((i+1)%2==1 && t%2==1)++out;
	}
	cout << out << endl;
	return 0;
}