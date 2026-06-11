#include <iostream>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	if(a==1&&b==2) cout<<'3';
	if(b==1&&a==2) cout<<'3';
	if(a==1&&b==3) cout<<'2';
	if(b==1&&a==3) cout<<'2';
	if(a==2&&b==3) cout<<'1';
	if(b==2&&a==3) cout<<'1';
	return 0;
}