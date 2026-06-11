#include<iostream>
using namespace std;
int main(){
	bool num[250000] = {true,true,};
	for(int i=2; i<500; i++){
		if(!num[i]){
			for(int j=i*i; j<250000; j+=i){
				num[j] = true;
			}
		}
	}
	for(;;){
		int n,sum = 0;
		cin >>n;
		if(!n){break;}
		for(int i=n+1; i<=n*2; i++){
			if(!num[i]){sum++;}
		}
		cout <<sum<<endl;
	}
	return 0;
}