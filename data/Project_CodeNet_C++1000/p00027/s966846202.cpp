#include<iostream>
using namespace std;
int main(){
	int m=0,d=0,n=0,date[50]={0},i=0;
	while(cin>>m&&m!=0){
		cin>>d;
		switch(m){
			case 1:
				break;
			case 2:
				d=d+3;
				break;
			case 3:
				d=d+4;
				break;
			case 4:
				break;
			case 5:
				d=d+2;
				break;
			case 6:
				d=d+5;
				break;
			case 7:
				break;
			case 8:
				d=d+3;
				break;
			case 9:
				d=d+6;
				break;
			case 10:
				d=d+1;
				break;
			case 11:
				d=d+4;
				break;
			case 12:
				d=d+6;
				break;
		}
		date[i]=d%7;
		i++;
		n++;
	}
	for(int i=0;i<n;i++){
		switch(date[i]){
			case 0:
				cout<<"Wednesday"<<endl;
				break;
			case 1:
				cout<<"Thursday"<<endl;
				break;
			case 2:
				cout<<"Friday"<<endl;
				break;
			case 3:
				cout<<"Saturday"<<endl;
				break;
			case 4:
				cout<<"Sunday"<<endl;
				break;
			case 5:
				cout<<"Monday"<<endl;
				break;
			case 6:
				cout<<"Tuesday"<<endl;
				break;
		}
	}
}