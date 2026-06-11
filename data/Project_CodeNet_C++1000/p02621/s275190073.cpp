#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main(){
	double x,s=0;
	while(cin>>x){
		for(int i=1;i<=3;i++){
			s+=pow(x,i);
		}
		cout<<s<<endl;
	}
	return 0;
}