#include <iostream>
using namespace std;
int main(){
	for (;;){
		int a,goukei=0,max=-999999999,b;
		cin>>a;
		if (a==0)break;
		int data[a+1]={0};
		for (int A=1;A<=a;A++){
			cin>>data[A];
			if (max<data[A])max=data[A];
			goukei+=data[A];
			data[A]=goukei;
			if (max<data[A])max=data[A];
		}max=-999999999;
		for (int A=1;A<=a;A++){
			b=A-2;
			for (int B=A-1;B>=0;B--){
				goukei=0;
				goukei=data[A]-data[B];
				if (goukei>max) max=goukei;
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
	
		
		
			