#include<iostream> 
using namespace std; 
int main()
{
	int A,B,K,i;
	string a="NG";
	scanf("%d%d%d",&K,&A,&B);
	for(i=A;i<=B;i++){
		if(i%K==0){
			a="OK";
		}
	}
	cout<<a;	
	return 0;
}