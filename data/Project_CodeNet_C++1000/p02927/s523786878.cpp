#include<bits/stdc++.h>
using namespace std;
int main(){
	int M,D,x=0;
	cin>>M>>D;
	for (int i=1;i<=M;i++){
		for(int j=1;j<=D;j++){
			if (j>=10){
				int u,d;
				u=j%10;
				d=(j-u)/10;
				if((d*u)==i && d>=2 && u>=2){
					x++;
				
				}
			}
		}
	
	
	}
cout<<x;






}