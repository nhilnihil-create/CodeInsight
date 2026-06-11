#include<iostream>
using namespace std;
int main(){
	int x=1,y=1;
	while(1){
		cout << x << "x" << y << "=" << x*y << endl;
		y=y+1;
		if(x==9&&y==10)break;
		else if(y==10){
			y=1;x=x+1;
		}
	}
	
	return 0;
}