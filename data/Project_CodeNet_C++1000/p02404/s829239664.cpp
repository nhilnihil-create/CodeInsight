#include<iostream>
using namespace std;
int main(){
	int h,w;
for(;;){
	cin>>h>>w;
    if(h==0||w==0){
		   break;
	}
	for(int j=1;j<=h;j++){
	for(int i=1;i<=w;i++){
		if(j==1||j==h||i==1||i==w){
			cout<<"#";
		}else{
			cout<<".";
		}
	}
	cout<<endl;
	}
	cout<<endl;
}
}