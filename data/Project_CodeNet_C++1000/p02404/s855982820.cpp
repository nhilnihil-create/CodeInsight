#include<iostream>
using namespace std;
int a[10000];
int b[10000];
int main(){
	int h=0;
	int w=0;
	int i=0;
	int x=0;
	int y=0;
	int z=0;
	while(1){
		cin>>h>>w;
		if(h==0&&w==0){
			break;
		}
		a[i]=h; //y
		b[i]=w; //x
		i++;
	}
	for(z=0;z<i;z++){
		for(y=0;y<a[z];y++){
			for(x=0;x<b[z];x++){
				if(x==0||y==0||x==b[z]-1||y==a[z]-1){
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
		