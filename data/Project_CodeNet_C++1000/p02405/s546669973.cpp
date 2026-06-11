#include<iostream>
using namespace std;
int main(){
	int w,h,a,b;
	while(1){
		cin>>h>>w;
		if(h==0&&w==0){break;}
		for(b=0;b<h;b++){
			for(a=0;a<w;a++){
				if((b%2)==0&&b!=1){
					if((a%2)==0&&a!=1){
						cout<<'#';
					}else if((a%2)!=0||a==1){
						cout<<'.';
					}
				}else if((b%2)!=0||b==1){
					if((a%2)==0&&a!=1){
						cout<<'.';
					}else if((a%2)!=0||a==1){
						cout<<'#';
					}
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}