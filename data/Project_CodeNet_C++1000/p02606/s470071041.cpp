#include<iostream>
using namespace std;

int main(){
	int a,b;
	int k;
	int count=0;
	cin>>a>>b;
	cin>>k;
	for(int i=a;i<=b;i++){
		if(i%k==0){
			count++;
		}
	}
	cout<<count<<endl;
	
}