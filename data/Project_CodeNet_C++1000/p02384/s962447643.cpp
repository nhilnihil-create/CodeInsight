#include<iostream>
using namespace std;

int main(){
	int a[6],num,x,y;
	for(int i=0;i<6;i++)cin>>a[i];
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>x>>y;
		if(x==a[0]&&y==a[1]||x==a[1]&&y==a[5]||x==a[5]&&y==a[4]||x==a[4]&&y==a[0]){
			cout<<a[2]<<endl;
		}

		if(x==a[1]&&y==a[0]||x==a[5]&&y==a[1]||x==a[4]&&y==a[5]||x==a[0]&&y==a[4]){
			cout<<a[3]<<endl;
		}

		if(x==a[3]&&y==a[1]||x==a[1]&&y==a[2]||x==a[2]&&y==a[4]||x==a[4]&&y==a[3]){
			cout<<a[0]<<endl;
		}

		if(x==a[1]&&y==a[3]||x==a[2]&&y==a[1]||x==a[4]&&y==a[2]||x==a[3]&&y==a[4]){
			cout<<a[5]<<endl;
		}

		if(x==a[0]&&y==a[3]||x==a[3]&&y==a[5]||x==a[5]&&y==a[2]||x==a[2]&&y==a[0]){
			cout<<a[1]<<endl;
		}

		if(x==a[3]&&y==a[0]||x==a[5]&&y==a[3]||x==a[2]&&y==a[5]||x==a[0]&&y==a[2]){
			cout<<a[4]<<endl;
		}		
	}
}
