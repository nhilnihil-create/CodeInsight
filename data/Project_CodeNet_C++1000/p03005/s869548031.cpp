#include <iostream>
using namespace std;

int main() {
	int n,k,out;cin>>n>>k;
	if(k==1){
		cout << 0<< endl;
	} else {
		cout << n-k << endl;
	}
	return 0;
}