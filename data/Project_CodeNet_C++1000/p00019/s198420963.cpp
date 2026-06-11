#include<iostream>
using namespace std;
int main(){
	int n;
	while((cin>>n)!=NULL){
		long long fac=n;
		while(--n>0)fac*=n;
		cout<<fac<<endl;
	}
	return 0;
}