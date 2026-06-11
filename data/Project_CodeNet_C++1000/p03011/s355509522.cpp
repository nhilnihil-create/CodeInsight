#include<bits/stdc++.h>	
using namespace std;

int main(){
	int a, b, c, d[3], aux;
	cin>>a;
	cin>>b;
	cin>>c;
	d[0]=a+b;
	d[1]=b+c;
	d[2]=a+c;
	for(int i=0; i<2;i++){
 		for (int j=0; j<2; j++){
 			if(d[j]>d[j+1]){
 				aux=d[j];
 				d[j]=d[j+1];
 				d[j+1]=aux;
 			}
 		}
 	}
 	cout<<d[0]<<endl;
}