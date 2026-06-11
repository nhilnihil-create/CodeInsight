#include<iostream>
#include<string>
using namespace std;
int main(){
	int h=0; //??????
	int w=0; //??????
	int a[10000];
	int b[10000];
	int i=0;
	int x=0;
	int y=0;
	int z=0;
	while(1){
		cin>>w>>h;
		if(w==0&&h==0){
			break;
		}
		a[i]=w;
		b[i]=h;
		i++;
	}
	for(x=0;x<i;x++){
		for(y=0;y<a[x];y++){
			for(z=0;z<b[x];z++){
				cout<<"#";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}