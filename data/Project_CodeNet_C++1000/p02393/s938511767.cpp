#include <iostream>
using namespace std;
int main(){
	int a[3],b,n,j,i,k;
	for(n=0;n<3;n++){
		cin>>a[n];
	}
		for(n=0;n<2;n++){
			for(j=n+1;j<3;j++){
				if(a[n]>a[j]){
					i=a[n];
					a[n]=a[j];
					a[j]=i;
				}
			}
		}
		for(k=0;k<2;k++){
			cout<<a[k]<<" ";
		}
		cout<<a[2]<<endl;
	return 0;
}