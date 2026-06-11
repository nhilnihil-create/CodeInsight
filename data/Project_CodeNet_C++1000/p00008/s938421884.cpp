#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a,b,c,d,n,x,sum=0,i;
	for(i=0;i<50;i++){
		cin>>x;
	for(a=0;a<=9;a++){
		for(b=0;b<=9;b++){
			for(c=0;c<=9;c++){
				for(d=0;d<=9;d++){
					n=a+b+c+d;
					if(x==n){
						sum++;
					}
				}
			}
		}
	}
	cout<<sum<<endl;
	sum=0;
	}
	return 0;
}