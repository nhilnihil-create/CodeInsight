#include <iostream>
using namespace std;

int main() {
	int a,b,c;
	cin>>a>>b>>c;

	if(b+c<=a)
	   cout<<"0";
	else{
		while(a!=b){
	      b=b+1;
	      c=c-1;

		 }
         cout<<c;
	}
	return 0;
}
