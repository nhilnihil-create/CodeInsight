#include<iostream>
using namespace std;
int main(){
	while(1){
		int a,b,ans=0;
		cin>>a>>b;
		if(a==0)break;
		a--;
		int c[12]={31,29,31,30,31,30,31,31,30,31,30,31};
		for(int i=0;i<a;i++){
			ans+=c[i];
		}
		ans+=b;
		if(ans%7==1){
			cout<<"Thursday"<<endl;
		}
		if(ans%7==2){
			cout<<"Friday"<<endl;
		}
		if(ans%7==3){
			cout<<"Saturday"<<endl;
		}
		if(ans%7==4){
			cout<<"Sunday"<<endl;
		}
		if(ans%7==5){
			cout<<"Monday"<<endl;
		}
		if(ans%7==6){
			cout<<"Tuesday"<<endl;
		}
		if(ans%7==0){
			cout<<"Wednesday"<<endl;
		}
	}
	return 0;
}

