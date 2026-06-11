#include<bits/stdc++.h>
using namespace std;

bool x[300000]={};//false is prime
int y[100000]={};

int main(){
	int a;
	for (int i=2;i<260000;i++){
		for (int j=2;j<260000/i;j++){
			x[i*j]=1;
		}
	}
	x[0]=1;
	x[1]=1;
	int k=0;
	for (int i=2;i<260000;i++){
		if (x[i]==0){
			y[k]=i;
			k++;
		}
	}
		while(1){
		cin>>a;
		if (a==0) return 0;
		else {
			cout<<(upper_bound(y,y+k,a*2)-y)-(upper_bound(y,y+k,a)-y)<<endl;
			
		}
	}
}
