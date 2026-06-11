#include<iostream>
using namespace std;
int qql(int x,int y){
	cout<<x<<"x"<<y<<"="<<x*y<<endl;
}
int main(){
	int x,y;
	for(x = 1;x < 10;x ++){
		for(y = 1;y < 10;y ++){
			qql(x,y);
		}
	}
	return 0;
}