#include<iostream>
using namespace std;
int main(){
	int a,b,c,d,k=0;
	cin>>a>>b>>c>>d;
	if((a<b)&&(b<c)){
		cout<<"Yes";
	}
	else{
			do{
		k++;
		if(a>=c){
			c=c*2;
		}
		else{
			if(b<=a){
				b=b*2;
			}
			else{
				if(b>=c){
					c=c*2;
				}
			}
		}
		if((a<b)&&(b<c)){
			break;
		}
	}while(1<2);
	if(k<=d){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	}
}