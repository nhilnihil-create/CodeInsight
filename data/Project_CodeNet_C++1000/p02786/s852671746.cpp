#include <iostream>

using namespace std;

long long int m(long long int h){

	if(h==1){
	
		return 1;
	}
	return m(h/2)*2+1;
}
int main(){

	long long int h;
	cin>>h;
	cout<<m(h)<<'\n';
	return 0;
}
