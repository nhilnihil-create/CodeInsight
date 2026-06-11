#include <iostream>
using namespace std;
char d[100000000],h[1000],h2[1000];
int main(){
	int hN,dN;
	while(1){
	cin>>hN;
	if(hN==0) break;
	for(int i=0;i<hN;i++){
		cin>>h[i]>>h2[i];
	}
	cin>>dN;
	for(int i=0;i<dN;i++){
		cin>>d[i];
	}
	for(int i=0;i<dN;i++){
		for(int j=0;j<hN;j++){
			if(d[i]==h[j]){
				d[i]=h2[j];
				break;
			}
		}
		cout<<d[i];
	}
	cout<<endl;
	}
	return 0;
}