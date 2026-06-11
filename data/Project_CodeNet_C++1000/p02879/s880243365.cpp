#include <iostream>
using namespace std;

int main() {
	int b,c;
	cin>>b>>c;
	if(b<=9&&b>=1&&c<=9&&c>=1){
	    cout<<b*c<<endl;
	}
	else{
	    cout<<-1<<endl;
	}
	return 0;
}