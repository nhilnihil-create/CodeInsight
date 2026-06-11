#include <iostream>
using namespace std;

int main() {
	int A1;
	int A2;
	int A3;
	cin>>A1>>A2>>A3;
	int sum=A1+A2+A3;
	if(sum>=22){
		cout<<"bust"<<endl;
	}
	else
	cout<<"win"<<endl;
	return 0;
}