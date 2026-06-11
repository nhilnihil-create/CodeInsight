#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,count = 0,f = 0;
	cin>>a;
	int moto[a+1];
	for(int i = 0;i<a;i++){
		cin>>moto[i];
	}
	cin>>b;
	int aru[b];
	for(int i = 0;i<b;i++){
		cin>>aru[i];
	}
	for(int i = 0;i<b;i++){
		moto[a] = aru[i];
		int j = 0;
		while(moto[j] != aru[i]){
			j++;
			if(j>=a){
				f = 1;
			}
		}
		if(f == 0){
			count++;
		}
		f = 0;
	}
	cout<<count<<endl;
}
