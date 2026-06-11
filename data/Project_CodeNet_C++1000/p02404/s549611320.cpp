#include<iostream>
using namespace std;
int main(){
	int w,h,a,b;
	while(1){
	cin>>h>>w;
	if(h==0&&w==0){
		break;
	}
	w-=2;
	a=w;
	b=h;
	for(;h>0;h--){
		cout<<'#';
		for(w=a;w>0;w--){
			if(h==b||h==1){
				cout<<'#';
			}else{
				cout<<'.';
			}
		}
		cout<<'#';
		cout<<endl;
	}
	cout<<endl;
	}
	return 0;
}