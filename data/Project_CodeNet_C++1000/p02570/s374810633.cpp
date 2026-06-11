#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int d=0, t=0,s=0;
	double sum=0;
	cin>>d>>t>>s;
	sum=(double)d/t;
	if(sum>s)
	 cout<<"No"<<endl;
	else
	 cout<<"Yes"<<endl;
	return 0;
}