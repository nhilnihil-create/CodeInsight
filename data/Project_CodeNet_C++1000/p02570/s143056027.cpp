#include <iostream>
using namespace std;

int main(){
	int d,t,s;
	cin>>d>>t>>s;
	double time=(double)d/s;
	if(time>t){
		cout << "No" <<endl;
	}
	else{
		cout << "Yes" <<endl;
	}
	return 0;
}