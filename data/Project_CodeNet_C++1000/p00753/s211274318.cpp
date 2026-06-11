#include<iostream>
using namespace std;
#define MAX_N 400000
bool prime[MAX_N];
int num[MAX_N];
int main(){
	for(int i=0;i<MAX_N;i++){
		prime[i]=1;
	}
	prime[0]=0;
	prime[1]=0;
	for(int i=2;i<MAX_N;i++){
		if(prime[i]){
			for(int j=2;j*i<MAX_N;j++){
				prime[i*j]=0;
			}
		}
	}
	for(int i=1;i<MAX_N;i++){
		if(prime[i]){
			num[i]=num[i-1]+1;
		}else{
			num[i]=num[i-1];
		}
	}
	int a;
	while(cin>>a&& a!=0){
		cout<<num[a*2]-num[a]<<endl;
	}

}