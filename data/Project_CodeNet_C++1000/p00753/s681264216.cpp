#include<iostream>

using namespace std;

#define NMAX 123456

int main(){

	bool zaru[NMAX*2+1];
	int n,c;

	for(int i=0;i<NMAX*2+1;i++){
		zaru[i]=true;
	}
	zaru[0]=false;
	zaru[1]=false;

	for(int i=0;i<NMAX*2+1;i++){
		if(zaru[i]){
			for(int j=i*2;j<NMAX*2+1;j+=i){
				zaru[j]=false;
			}
		}
	}

	while(1){

		cin>>n;
		if(n==0) break;

		c=0;
		for(int i=n+1;i<=2*n;i++){
			if(zaru[i]) c++;
		}
		cout<<c<<endl;
	}
}