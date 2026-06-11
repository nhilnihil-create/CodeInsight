#include <iostream>
using namespace std;

int main(){
	int x, y, z;
  	cin>>x>>y>>z;
  
  	int tmp=x;
  	x=y;
  	y=tmp;
  	
  	tmp=x;
  	x=z;
  	z=tmp;
  	
  	cout<<x<<" "<<y<<" "<<z<<endl;

}