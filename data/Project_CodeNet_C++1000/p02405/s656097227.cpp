#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;
int main(){
    int h,w;
	int a=0;
	while(true){
		cin>>h>>w;
		a=0;
		if(h==0&&w==0)
			break;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(a%2==0)
				cout<<"#";
			else
				cout<<".";
			a++;
		}
		cout<<endl;
		a-=w%2+1;
	}
	cout<<endl;
	}
	return 0;
}