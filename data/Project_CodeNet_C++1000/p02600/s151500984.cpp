#include <iostream>
using namespace std;

int main() {
	int X;
	cin>>X;
	if(X<=599)cout<<"8";
	else if(X<=799)cout<<"7";
	else if(X<=999)cout<<"6";
	else if(X<=1199)cout<<"5";
	else if(X<=1399)cout<<"4";
	else if(X<=1599)cout<<"3";
	else if(X<=1799)cout<<"2";
	else cout<<"1";
	return 0;
}
