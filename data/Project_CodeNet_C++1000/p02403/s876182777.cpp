#include<iostream>
using namespace std;
int main(){
	int w,h,a;
	while(1){
	cin>>h>>w;
	a=w;
	if(h==0&&w==0){
		break;
	}
	for(;h>0;h--){	
		for(w=a;w>0;w--){
			cout<<'#';
		}
		cout<<endl;
	}
	cout<<endl;
	}
	return 0;
}