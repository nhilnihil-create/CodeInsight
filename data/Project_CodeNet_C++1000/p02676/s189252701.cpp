#include <bits/stdc++.h>
using namespace std;

int main(){
	int tam, K, i;
	char cadena[100];
	cin>>K;
	cin>>cadena;
	if(strlen(cadena)<=K){
		cout<<cadena<<endl;
	}else{
		for(i=0; i<K; i++){
			cout<<cadena[i];
		}cout<<"..."<<endl;
	}
}