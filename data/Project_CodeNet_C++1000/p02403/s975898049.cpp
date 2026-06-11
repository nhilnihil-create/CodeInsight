#include <iostream>
#include <string>
using namespace std;
int main() {
	int h,w,a,b;
	for(;;){
		cin>>h>>w;
		if(h==0 && w==0){
			return 0;
		}
		a=h;
		b=w;
		for(h=a;h>0;h=h-1){
			for(w=b;w>0;w=w-1){
				cout<<"#";
			}
			cout<<endl;	
		}
		cout<<endl;
	}
}

