#include<iostream>
using namespace std;
main(){
	int n;
	while(cin>>n){
		int sum=0;
		for(int i=0;i<600;i+=n)sum+=i*i*n;
		cout<<sum<<endl;
	}
}