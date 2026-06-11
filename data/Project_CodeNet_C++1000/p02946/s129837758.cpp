#include <iostream>
using namespace std;

int main() {
	int k,x;
	cin>>k>>x;
	int s=x-k+1;
	int e=x+k-1;
	for(int i=s;i<=e;i++){
		cout<<i<<" ";
	}
	return 0;
}