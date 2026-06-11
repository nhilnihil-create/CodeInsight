#include<iostream>
using namespace std;
int main(){
	int d,r;
	do{
	cin >>d>>r;
	if(d==0||r==0)
		break;
	for(int i=0;i<d;i++){
		for(int j=0;j<r;j++)
			cout <<"#";
		cout<<endl;
	}
	cout<<endl;
	}while(1);
	return 0;
}