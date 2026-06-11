#include<iostream>
using namespace std;
int main() {
	int a,i,n;
	bool b=true;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a;
		if(a%2==0){
			if((a%3!=0)&&(a%5!=0)){
				b=false;
				break;
			}
		}
	}
	if(b==true) cout<<"APPROVED"<<endl;
	else cout<<"DENIED"<<endl;
	return 0;
}