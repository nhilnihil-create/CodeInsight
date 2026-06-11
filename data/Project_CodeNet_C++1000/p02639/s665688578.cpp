#include <iostream>
using namespace std;
int main(){
	int x[5],c;
	for(int i=0;i<5;i++){
		cin>>x[i];
		if(x[i]==0)
		{
			c=i+1;
			break;
		}
	}
	printf("%d",c);
}